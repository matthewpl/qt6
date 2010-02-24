#include "widget.hpp"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
	QTextCodec::setCodecForTr (QTextCodec::codecForName ("UTF-8"));

	coRysowac = kolo;
	px = 0;
	py = 0;
	dynamicznie = false;

	qaKolo = new QAction(tr("Koło"), this);
	connect(qaKolo, SIGNAL(triggered()), this, SLOT(ustawKolo()));

	qaKwadrat = new QAction(tr("Kwadrat"), this);
	connect(qaKwadrat, SIGNAL(triggered()), this, SLOT(ustawKwadrat()));

	qaNapis = new QAction(tr("Napis"), this);
	connect(qaNapis, SIGNAL(triggered()), this, SLOT(ustawNapis()));

	qaDynamicznie = new QAction(tr("Zmienny rozmiar"), this);
	qaDynamicznie->setCheckable(true);
	connect(qaDynamicznie, SIGNAL(triggered()), this, SLOT(ustawDynamicznie()));
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *e)
{
	if (narysuj)
	{
		QPainter painter(this);

		QColor kolor(255, 0, 255);

		painter.setPen(kolor);

		switch(coRysowac)
		{
		case kolo:
			painter.drawEllipse(x-50, y-50, 100+px, 100+py);
			break;

		case kwadrat:
			painter.drawRect(x-50, y-50, 100+px, 100+py);
			break;

		case napis:
			painter.drawText(x, y, "http://blog.matthew.org.pl/");
			break;

		default:
			break;
		}

		narysuj = false;
	}
}

void Widget::mousePressEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
	{
		px = 0;
		py = 0;
		x = e->x();
		y = e->y();
		narysuj = true;
		update();
	}
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
	if(dynamicznie)
	{
		px = e->x() - x;
		py = e->y() - y;
		narysuj = true;
		update();
	}
}

void Widget::contextMenuEvent(QContextMenuEvent *e)
{
	QMenu menu(this);

	menu.addAction(qaKolo);
	menu.addAction(qaKwadrat);
	menu.addAction(qaNapis);
	menu.addSeparator();
	menu.addAction(qaDynamicznie);
	menu.exec(e->globalPos());
}

void Widget::ustawKolo()
{
	coRysowac = kolo;
}

void Widget::ustawKwadrat()
{
	coRysowac = kwadrat;
}

void Widget::ustawNapis()
{
	coRysowac = napis;
}

void Widget::ustawDynamicznie()
{
	if (dynamicznie)
		dynamicznie = false;
	else
		dynamicznie = true;
}
