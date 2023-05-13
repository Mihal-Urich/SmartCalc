#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "alg.c"

QString str, str_buf;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->textEdit->setReadOnly(true);
  ui->textEdit_2->setText("-10");
  ui->textEdit_3->setText("10");
  ui->textEdit_4->setText("-10");
  ui->textEdit_5->setText("10");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c == ')') {
    str.append("*1");
    ui->textEdit->setText(str);
  } else {
    str.append("1");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_2_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c == ')') {
    str.append("*2");
    ui->textEdit->setText(str);
  } else {
    str.append("2");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_3_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c == ')') {
    str.append("*3");
    ui->textEdit->setText(str);
  } else {
    str.append("3");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_4_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c == ')') {
    str.append("*4");
    ui->textEdit->setText(str);
  } else {
    str.append("4");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_19_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c == ')') {
    str.append("*5");
    ui->textEdit->setText(str);
  } else {
    str.append("5");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_8_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c == ')') {
    str.append("*6");
    ui->textEdit->setText(str);
  } else {
    str.append("6");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_7_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c == ')') {
    str.append("*7");
    ui->textEdit->setText(str);
  } else {
    str.append("7");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_5_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c == ')') {
    str.append("*8");
    ui->textEdit->setText(str);
  } else {
    str.append("8");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_6_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c == ')') {
    str.append("*9");
    ui->textEdit->setText(str);
  } else {
    str.append("9");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_31_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c == ')') {
    str.append("*0");
    ui->textEdit->setText(str);
  } else {
    str.append("0");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_10_clicked() {
  QChar c = str.data()[str.size() - 1];
  QString check_oper = "1234567890X";
  if (c != '.') {
    if ((check_oper.count(c) != 0) || (c == '(') || (c == ')')) {
      str.append("+");
      ui->textEdit->setText(str);
    } else {
      str.append("(+");
      ui->textEdit->setText(str);
    }
  }
}

void MainWindow::on_pushButton_11_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c != '.') {
    QString check_oper = "1234567890X";
    if ((check_oper.count(c) != 0) || (c == '(') || (c == ')')) {
      str.append("-");
      ui->textEdit->setText(str);
    } else {
      str.append("(-");
      ui->textEdit->setText(str);
    }
  }
}

void MainWindow::on_pushButton_9_clicked() {
  QChar c = str.data()[str.size() - 1];
  if ((c != '(') && (c != '.') && (c != '+') && (c != '-')) {
    QString check_oper = "/%*^";
    if (check_oper.count(c) != 0) {
      str[str.size() - 1] = '*';
      ui->textEdit->setText(str);
    } else {
      str.append("*");
      ui->textEdit->setText(str);
    }
  }
}

void MainWindow::on_pushButton_12_clicked() {
  QChar c = str.data()[str.size() - 1];
  if ((c != '(') && (c != '.') && (c != '+') && (c != '-')) {
    QString check_oper = "/%*^";
    if (check_oper.count(c) != 0) {
      str[str.size() - 1] = '/';
      ui->textEdit->setText(str);
    } else {
      str.append("/");
      ui->textEdit->setText(str);
    }
  }
}

void MainWindow::on_pushButton_14_clicked() {
  QChar c = str.data()[str.size() - 1];
  QChar buf = c;
  QString oper = "+-*/^%()";
  int fl = 1, i = 0;
  while (oper.count(buf) == 0) {
    if (buf == '.') {
      fl = 0;
      break;
    } else {
      fl = 1;
    }
    i++;
    buf = str.data()[str.size() - i];
  }
  if (fl == 1) {
    if ((c >= '0') && (c <= '9')) {
      str.append(".");
      ui->textEdit->setText(str);
    } else if (c != '.') {
      str.append("0.");
      ui->textEdit->setText(str);
    }
  }
}

void MainWindow::on_pushButton_15_clicked() /* обработка скобок*/
{
  QChar c = str.data()[str.size() - 1];
  if (c != '.') {
    int left = 0, right = 0;
    left = str.count('(');
    right = str.count(')');
    if ((left > right) &&
        (((c >= '0') && (c <= '9')) || (c == ')') || (c == 'X'))) {
      str.append(")");
      ui->textEdit->setText(str);
    } else {
      QString buf = "+-*/^%(";
      if ((buf.count(c) != 0) || (str.size() == 0)) {
        str.append("(");
        ui->textEdit->setText(str);
      } else {
        str.append("*(");
        ui->textEdit->setText(str);
      }
    }
  }
}

void MainWindow::on_pushButton_13_clicked() {
  QChar c = str.data()[str.size() - 1];
  if ((c != '(') && (c != '.') && (c != '+') && (c != '-')) {
    QString check_oper = "/%*^";
    if (check_oper.count(c) != 0) {
      str[str.size() - 1] = '%';
      ui->textEdit->setText(str);
    } else {
      str.append("%");
      ui->textEdit->setText(str);
    }
  }
}

void MainWindow::on_pushButton_16_clicked() {
  QChar c = str.data()[str.size() - 1];
  if ((c != '(') && (c != '.') && (c != '+') && (c != '-')) {
    QString check_oper = "/%*^";
    if (check_oper.count(c) != 0) {
      str[str.size() - 1] = '^';
      ui->textEdit->setText(str);
    } else {
      str.append("^");
      ui->textEdit->setText(str);
    }
  }
}

void MainWindow::on_pushButton_29_clicked() /* обработка запроса на ответ */
{
  QString buf = ui->textEdit_6->toPlainText();
  double res = -1;
  char tmp_str[255];

  if (str.size() > 0) {
    int left = str.count('(');
    int right = str.count(')');
    if (left > right) {
      for (int i = left - right; i > 0; --i) {
        str.append(')');
      }
    }

    for (int i = 0; i < str.size(); ++i) {
      tmp_str[i] = str[i].toLatin1();
      tmp_str[i + 1] = '\0';
    }

    if (str.count('X') == 0) {
      if (str.size() > 0) {
        res = begin(tmp_str, 0);
      }
    } else {
      if ((str.size() > 0) && (buf.size() > 0)) {
        res = begin(tmp_str, buf.toDouble());
      } else {
        res = sqrt(-1);
      }
    }
    str.clear();
    ui->textEdit->setText(str);
    ui->textEdit->setText(QString::fromStdString(std::to_string(res)));
  }
}

void MainWindow::on_pushButton_26_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c != '.') {
    str.append("sqrt(");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_17_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c != '.') {
    str.append("cos(");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_25_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c != '.') {
    str.append("acos(");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_18_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c != '.') {
    str.append("sin(");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_23_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c != '.') {
    str.append("asin(");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_21_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c != '.') {
    str.append("tan(");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_22_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c != '.') {
    str.append("atan(");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_20_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c != '.') {
    str.append("ln(");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_24_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c != '.') {
    str.append("log(");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_textEdit_textChanged() {
  str.clear();
  str = ui->textEdit->toPlainText();
}

void MainWindow::on_pushButton_27_clicked() {
  str.clear();
  ui->textEdit->setText(str);
}

void MainWindow::on_pushButton_28_clicked() {
  QChar c = str.data()[str.size() - 1];
  if (c != '.') {
    str.append("X");
    ui->textEdit->setText(str);
  }
}

void MainWindow::on_pushButton_30_clicked() {
  QString nan = {"nan"};
  if ((str.size() > 0) && (str != nan)) {
    double x_begin, x_end, y_begin, y_end, step = 0.01, now_x, now_y;
    int many_point;
    QString buf;

    buf.append(ui->textEdit_2->toPlainText());
    x_begin = buf.toDouble();
    buf.clear();
    buf.append(ui->textEdit_3->toPlainText());
    x_end = buf.toDouble() + step;
    buf.clear();
    buf.append(ui->textEdit_4->toPlainText());
    y_begin = buf.toDouble();
    buf.clear();
    buf.append(ui->textEdit_5->toPlainText());
    y_end = buf.toDouble() + step;
    buf.clear();

    QVector<double> x, y;

    int left = str.count('(');
    int right = str.count(')');
    if (left > right) {
      for (int i = left - right; i > 0; --i) {
        str.append(')');
      }
    }

    ui->widget->xAxis->setRange(x_begin, x_end);
    ui->widget->yAxis->setRange(y_begin, y_end);

    double tik = 0;
    int i = 0;

    char tmp_str[255];
    for (int i = 0; i < str.size(); ++i) {
      tmp_str[i] = str[i].toLatin1();
      tmp_str[i + 1] = '\0';
    }

    for (now_x = x_begin; now_x < x_end; now_x += step) {
      now_y = begin(tmp_str, now_x);
      if (now_y == now_y) {
        if (abs(abs(now_y) - abs(tik)) <= 15) {
          x.push_back(now_x);
          y.push_back(now_y);
          tik = now_y;
        } else {
          ui->widget->addGraph();
          ui->widget->graph(i)->addData(x, y);
          ui->widget->replot();
          x.clear();
          y.clear();
          tik = now_y;
          i++;
        }
      }
    }
    ui->widget->addGraph();
    ui->widget->graph(i)->addData(x, y);
    ui->widget->replot();
    x.clear();
    y.clear();
    while (i >= 0) {
      ui->widget->removeGraph(i);
      i--;
    }
  }
}

void MainWindow::on_pushButton_32_clicked() {
  ui->textEdit_10->clear();
  ui->textEdit_11->clear();
  ui->textEdit_12->clear();
  QString buf;
  double cred, proc, ego;
  buf.append(ui->textEdit_7->toPlainText());
  cred = buf.toDouble();
  buf.clear();
  buf.append(ui->textEdit_9->toPlainText());
  proc = buf.toDouble();
  buf.clear();
  buf.append(ui->textEdit_8->toPlainText());
  ego = buf.toDouble();
  buf.clear();

  if (ui->radioButton->isChecked()) {
    double proc_in_m, mns;
    proc_in_m = proc / (100 * 12);
    mns = ego * 12;

    double res_payd;
    res_payd = cred * (proc_in_m / (1 - pow(1 + proc_in_m, -mns)));
    ui->textEdit_10->setText(QString::fromStdString(
        std::to_string((int)((res_payd)*100) / (double)100)));
    ui->textEdit_11->setText(QString::fromStdString(
        std::to_string((int)((res_payd * mns - cred) * 100) / (double)100)));
    ui->textEdit_12->setText(QString::fromStdString(
        std::to_string((int)((res_payd * mns) * 100) / (double)100)));
  }
  if (ui->radioButton_2->isChecked()) {
    QString result;
    double all_pay = 0;
    double mns;
    mns = ego * 12;
    double body = cred, prebody = cred / mns;
    int mas[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < mns; ++i) {
      double res;
      res = (body * (proc / 100) * mas[i * 10 % 12]) / 365;
      body -= prebody;
      result.append(QString::fromStdString(
          std::to_string((int)((res + prebody) * 100) / (double)100)));
      result.append('\n');
      all_pay += res + prebody;
    }
    ui->textEdit_10->setText(result);
    ui->textEdit_11->setText(QString::fromStdString(
        std::to_string((int)((all_pay - cred) * 100) / (double)100)));
    ui->textEdit_12->setText(QString::fromStdString(
        std::to_string((int)(all_pay * 100) / (double)100)));
  }
}

void MainWindow::on_pushButton_33_clicked() {
  if (str.size() > 0) {
    str.chop(1);
    ui->textEdit->setText(str);
  }
}
