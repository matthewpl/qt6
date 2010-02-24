#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QtGui>

enum CoRysowac
{
	kolo, kwadrat, napis
};

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = 0);
	~Widget();

protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void contextMenuEvent(QContextMenuEvent *);

protected slots:
	void ustawKolo();
	void ustawKwadrat();
	void ustawNapis();
	void ustawDynamicznie();

private:
	CoRysowac coRysowac;
	bool narysuj;
	bool dynamicznie;
	int x;
	int y;
	int px;
	int py;

	QAction *qaKolo;
	QAction *qaKwadrat;
	QAction *qaNapis;
	QAction *qaDynamicznie;
};

#endif // WIDGET_HPP
