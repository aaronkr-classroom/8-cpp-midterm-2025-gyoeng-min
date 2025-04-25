//split.cpp
#include<cctype>// isspace()
#include <iostream>
#include<string>
#include<vector>

using namespace std;

typedef string::size_type str_sz;

vector <std::string> split(const string& s) {
	vector<string> ret;
	str_sz i = 0;

	//�Һ��� : ���ݱ��� [������ i, ������ i )������ �ִ�
	//���ڿ��� ó��
	while (i != s.size()) {
		//�����ϴ� ������� ����
		//�Һ���: ���ݱ��� [������ i, ������ i )������ �ִ�
		//���ڵ��� ��� ����
		while (i != s.size() && isspace(s[i])) {
			++i;
		}

		//������ ���� �ܾ��� ���� ó��
		str_sz j = i;

		//�Һ��� : ���ݱ��� [������ i, ������ i )������ �ִ�
		//���ڵ��� ��� ������ �ƴ�
		while (j != s.size() && !isspace(s[j])) {
			j++;
		}

		//������ �ƴ� ���ڵ��� ã���� ��
		if (i != j) {
			//i�������� j-i���� ���ڵ��� s�� ����
			ret.push_back(s.substr(i, j - i));
			i = j;
		}

	}
	return ret;
}

int main() {
	string s;

	//���ڿ��� �� �྿ �Է¹޾� ����
	while (getline(cin, s)) {
		vector<string> v = split(s);

		//����v�� ������ �ܾ ���� ���
		for (str_sz i = 0; i != v.size(); i++) {
			cout << v[i] << endl;
		}
	}
	return 0;
}