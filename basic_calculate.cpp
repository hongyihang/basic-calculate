#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<string>
#include<Windows.h>
#define EDIT "1.0.2"
using namespace std;
int main() {
	srand(static_cast<unsigned int>(time(0)));
	int first_number_, second_number_, round, operator_, result, users_result_, number, right_problem_ = 0;
	string formula;
	time_t start, now, total_bigin_, total_time_ = 0;
	vector<string> wrong_problem_, wrong_problem_result_, wrong_problem_users_result_;
	cout << "��ӭ�����������" << EDIT << endl;
	cout << "������������:";
	cin >> round;
	time(&total_bigin_);
	for (int i = 0; i < round; i++) {
		system("cls");
		cout << "��ӭ�����������" << EDIT << endl;
		operator_ = rand() % 4;
		switch (operator_) {
		case 0:
			first_number_ = rand() % 100, second_number_ = rand() % 100;
			formula = to_string(first_number_) + "+" + to_string(second_number_);
			result = first_number_ + second_number_;
			break;
		case 1:
			first_number_ = rand() % 100, second_number_ = rand() % 100;
			if (first_number_ < second_number_) {
				number = first_number_, first_number_ = second_number_, second_number_ = number;
			}
			formula = to_string(first_number_) + "-" + to_string(second_number_);
			result = first_number_ - second_number_;
			break;
		case 2:
			first_number_ = rand() % 100, second_number_ = rand() % 10;
			formula = to_string(first_number_) + "*" + to_string(second_number_);
			result = first_number_ * second_number_;
			break;
		case 3:
			do {
				first_number_ = rand() % 100, second_number_ = rand() % 10;
			} while (first_number_ % second_number_ != 0 || first_number_ < second_number_ || second_number_ == 0);
			formula = to_string(first_number_) + "/" + to_string(second_number_);
			result = first_number_ / second_number_;
			break;
		default:
			break;
		}
		cout << "��" << i + 1 << "��:" << formula << "=";
		cin >> users_result_;
		if (users_result_ == result) {
			cout << "��ϲ�㣬����ˣ�";
			right_problem_++;
		} else {
			cout << "���ź�������ˣ�" << endl;
			wrong_problem_.push_back(formula), wrong_problem_result_.push_back(to_string(result)), wrong_problem_users_result_.push_back(to_string(users_result_));
		}
		time(&now);
		total_time_ += (now - total_bigin_);
		time(&start);
		do {
			time(&now);
		} while (now - start <= 1.5);
	}

	system("cls");	cout << "��ӭ�����������" << EDIT << endl;
	cout << "����" << round << "�⣬��" << right_problem_ << "�⣬��ȷ��" << int(right_problem_ * 10000 / round) / 100 << "%������ʱ" << total_time_ << "��" << endl;
	if (!wrong_problem_.empty()) {
		cout << "���⼯:" << endl;
		for (int i = 0; i < wrong_problem_.size(); i++) {
			cout << wrong_problem_[i] << "=" << wrong_problem_result_[i] << "			��Ĵ�:" << wrong_problem_users_result_[i] << endl;
		}
	}
	system("pause");
	return 0;
}