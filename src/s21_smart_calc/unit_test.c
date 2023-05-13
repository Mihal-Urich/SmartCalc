#include <check.h>

#include "alg.h"
#define ACCURACY 1e-6

START_TEST(calc_test_1) {
  double result = 0.0;
  char input_string[256] = "(5+5)*-2";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, -20.000000, ACCURACY);
}

START_TEST(calc_test_2) {
  double result = 0.0;
  char input_string[256] = "(10+10*2)/-3";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, -10.000000);
}

START_TEST(calc_test_3) {
  double result = 0.0;
  char input_string[256] = "2.0/(3.0+2.0)*5.0";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 2.000000, ACCURACY);
}

START_TEST(calc_test_4) {
  double result = 0.0;
  char input_string[256] = "10.0+10.0*10.0";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 110.000000, ACCURACY);
}

START_TEST(calc_test_5) {
  double result = 0.0;
  char input_string[256] = "-5+-4*-2";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 3.000000, ACCURACY);
}

START_TEST(calc_test_6) {
  double result = 0.0;
  char input_string[256] = "-5.0%-3.0";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, -2.000000);
}

START_TEST(calc_test_7) {
  double result = 0.0;
  char input_string[256] = "1.0/2.0*(2.0-1.0)";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, 0.500000);
}

START_TEST(calc_test_8) {
  double result = 0.0;
  char input_string[256] = "1.1+2.0+(3.0*4.0)+(5.0+6.8)";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, 26.900000);
}

START_TEST(calc_test_9) {
  double result = 0.0;
  char input_string[256] = "1.10+2.0+(3.0-5.5)*(1.5 - 6.5)";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, 15.600000);
}

START_TEST(calc_test_10) {
  double result = 0.0;
  char input_string[256] = "6.6-1.1-2.2-3.3-4.4-5.5";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, -9.900000);
}

START_TEST(calc_test_11) {
  double result = 0.0;
  char input_string[256] = "1.1-2.2-3.3-4.4-5.5+6.6";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, -7.7000000, ACCURACY);
}

START_TEST(calc_test_12) {
  double result = 0.0;
  char input_string[256] = "-1.1*5";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, -5.5);
}

START_TEST(calc_test_13) {
  double result = 0.0;
  char input_string[256] = "2^2";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, 4.000000);
}

START_TEST(calc_test_14) {
  double result = 0.0;
  char input_string[256] = "5^3";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, 125.000000);
}

START_TEST(calc_test_15) {
  double result = 0.0;
  char input_string[256] = "2^2^3";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, 64.000000);
}

START_TEST(calc_test_16) {
  double result = 0.0;
  char input_string[256] = "(2^2)^3";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, 64.000000);
}

START_TEST(calc_test_17) {
  double result = 0.0;
  char input_string[256] = "-5+3*2^2";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, 7.000000);
}

START_TEST(calc_test_18) {
  double result = 0.0;
  char input_string[256] = "(2^2^3-200)/2";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, -68.000000);
}

START_TEST(calc_test_19) {
  double result = 0.0;
  char input_string[256] = "5%-1.5";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, 0);
}

START_TEST(calc_test_20) {
  double result = 0.0;
  char input_string[256] = "(5%-1.5*4)^2";
  result = begin(input_string, 0);
  ck_assert_double_eq(result, 0);
}

START_TEST(calc_test_21) {
  double result = 0.0;
  char input_string[256] = "sin(30)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, -0.988032, ACCURACY);
}

START_TEST(calc_test_22) {
  double result = 0.0;
  char input_string[256] = "sin(45)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.850904, ACCURACY);
}

START_TEST(calc_test_23) {
  double result = 0.0;
  char input_string[256] = "sin(60)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, -0.304811, ACCURACY);
}

START_TEST(calc_test_24) {
  double result = 0.0;
  char input_string[256] = "sin(90)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.893997, ACCURACY);
}

START_TEST(calc_test_25) {
  double result = 0.0;
  char input_string[256] = "sin(120)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.580611, ACCURACY);
}

START_TEST(calc_test_26) {
  double result = 0.0;
  char input_string[256] = "sin(180)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, -0.801153, ACCURACY);
}

START_TEST(calc_test_27) {
  double result = 0.0;
  char input_string[256] = "sin(270)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, -0.176046, ACCURACY);
}

START_TEST(calc_test_28) {
  double result = 0.0;
  char input_string[256] = "sin(360)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.958916, ACCURACY);
}

START_TEST(calc_test_29) {
  double result = 0.0;
  char input_string[256] = "sin(0)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.000000, ACCURACY);
}

START_TEST(calc_test_30) {
  double result = 0.0;
  char input_string[256] = "cos(30)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.154251, ACCURACY);
}

START_TEST(calc_test_31) {
  double result = 0.0;
  char input_string[256] = "cos(45)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.525322, ACCURACY);
}

START_TEST(calc_test_32) {
  double result = 0.0;
  char input_string[256] = "cos(90)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, -0.448074, ACCURACY);
}

START_TEST(calc_test_33) {
  double result = 0.0;
  char input_string[256] = "cos(120)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.814181, ACCURACY);
}

START_TEST(calc_test_34) {
  double result = 0.0;
  char input_string[256] = "cos(180)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, -0.598460, ACCURACY);
}

START_TEST(calc_test_35) {
  double result = 0.0;
  char input_string[256] = "cos(270)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.984382, ACCURACY);
}

START_TEST(calc_test_36) {
  double result = 0.0;
  char input_string[256] = "cos(360)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, -0.283691, ACCURACY);
}

START_TEST(calc_test_37) {
  double result = 0.0;
  char input_string[256] = "cos(0)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 1.000000, ACCURACY);
}

START_TEST(calc_test_38) {
  double result = 0.0;
  char input_string[256] = "tan(90)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, -1.995200, ACCURACY);
}

START_TEST(calc_test_39) {
  double result = 0.0;
  char input_string[256] = "tan(90)*sin(30)+(cos(45)^2)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 2.247284, ACCURACY);
}

START_TEST(calc_test_40) {
  double result = 0.0;
  char input_string[256] = "(sin(45)+cos(30)+tan(45)+tan(90))*2";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 1.25946, ACCURACY);
}

START_TEST(calc_test_41) {
  double result = 0.0;
  char input_string[256] = "tan(180)^2";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 1.792091, ACCURACY);
}

START_TEST(calc_test_43) {
  double result = 0.0;
  char input_string[256] = "asin(0.5)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.523598, ACCURACY);
}

START_TEST(calc_test_44) {
  double result = 0.0;
  char input_string[256] = "acos(0.5)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 1.047198, ACCURACY);
}

START_TEST(calc_test_45) {
  double result = 0.0;
  char input_string[256] = "acos(1)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.000000, ACCURACY);
}

START_TEST(calc_test_46) {
  double result = 0.0;
  char input_string[256] = "atan(0)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.000000, ACCURACY);
}

START_TEST(calc_test_47) {
  double result = 0.0;
  char input_string[256] = "atan(1)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 0.785398, ACCURACY);
}

START_TEST(calc_test_48) {
  double result = 0.0;
  char input_string[256] = "sqrt(100)/sqrt(25)*sqrt(121)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 22.000000, ACCURACY);
}

START_TEST(calc_test_49) {
  double result = 0.0;
  char input_string[256] = "ln(5)";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, 1.609438, ACCURACY);
}

START_TEST(calc_test_50) {
  double result = 0.0;
  char input_string[256] = "-5.0%-3.0";
  result = begin(input_string, 0);
  ck_assert_double_eq_tol(result, -2.000000, ACCURACY);
}

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  double result;

  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, calc_test_1);
  tcase_add_test(tc1_1, calc_test_2);
  tcase_add_test(tc1_1, calc_test_3);
  tcase_add_test(tc1_1, calc_test_4);
  tcase_add_test(tc1_1, calc_test_5);
  tcase_add_test(tc1_1, calc_test_6);
  tcase_add_test(tc1_1, calc_test_7);
  tcase_add_test(tc1_1, calc_test_8);
  tcase_add_test(tc1_1, calc_test_9);
  tcase_add_test(tc1_1, calc_test_10);
  tcase_add_test(tc1_1, calc_test_11);
  tcase_add_test(tc1_1, calc_test_12);
  tcase_add_test(tc1_1, calc_test_13);
  tcase_add_test(tc1_1, calc_test_14);
  tcase_add_test(tc1_1, calc_test_15);
  tcase_add_test(tc1_1, calc_test_16);
  tcase_add_test(tc1_1, calc_test_17);
  tcase_add_test(tc1_1, calc_test_18);
  tcase_add_test(tc1_1, calc_test_19);
  tcase_add_test(tc1_1, calc_test_20);
  tcase_add_test(tc1_1, calc_test_21);
  tcase_add_test(tc1_1, calc_test_22);
  tcase_add_test(tc1_1, calc_test_23);
  tcase_add_test(tc1_1, calc_test_24);
  tcase_add_test(tc1_1, calc_test_25);
  tcase_add_test(tc1_1, calc_test_26);
  tcase_add_test(tc1_1, calc_test_27);
  tcase_add_test(tc1_1, calc_test_28);
  tcase_add_test(tc1_1, calc_test_29);
  tcase_add_test(tc1_1, calc_test_30);
  tcase_add_test(tc1_1, calc_test_31);
  tcase_add_test(tc1_1, calc_test_32);
  tcase_add_test(tc1_1, calc_test_33);
  tcase_add_test(tc1_1, calc_test_34);
  tcase_add_test(tc1_1, calc_test_35);
  tcase_add_test(tc1_1, calc_test_36);
  tcase_add_test(tc1_1, calc_test_37);
  tcase_add_test(tc1_1, calc_test_38);
  tcase_add_test(tc1_1, calc_test_39);
  tcase_add_test(tc1_1, calc_test_40);
  tcase_add_test(tc1_1, calc_test_41);
  tcase_add_test(tc1_1, calc_test_43);
  tcase_add_test(tc1_1, calc_test_44);
  tcase_add_test(tc1_1, calc_test_45);
  tcase_add_test(tc1_1, calc_test_46);
  tcase_add_test(tc1_1, calc_test_47);
  tcase_add_test(tc1_1, calc_test_48);
  tcase_add_test(tc1_1, calc_test_49);
  tcase_add_test(tc1_1, calc_test_50);

  srunner_run_all(sr, CK_ENV);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result == 0 ? 0 : 1;
}
