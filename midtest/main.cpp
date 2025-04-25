#include "midterm.h"
#include <iostream>
#include <vector>

int main() {
    int studentCount = 0;
    std::vector<Student> students;

    std::cout << "�л� ���� �Է��ϼ���: ";
    std::string input;
    std::getline(std::cin, input);

    // std::getline ���� �Է��� s.name�� �����ϰ�,
    // ������ ���Ե� �̸��� ���� �� �ְ� ��.
    // ���� ��� gyeong min�� ���а� gyeong�� �о����� min���� �а����� 

    if (!input.empty() && Number(input)) {
        studentCount = std::stoi(input);  // ���ڿ��� ������ ��ȯ�Ͽ� studentCount�� ����
    }

    // ���� ���
    for (int i = 0; i < studentCount; ++i) {
        std::cout << "\n== �л� " << (i + 1) << " ==\n";
        Student s;

        // �̸� �Է¹ޱ�
        std::cout << "�̸��� �Է��ϼ���: ";
        std::getline(std::cin, s.name);

        s.scores = Scores();  // ���� �Է¹ޱ�
        s.average = Average(s.scores);  // ��� ��� �� ����

        students.push_back(s);  // ���Ϳ� �л� ��ü �߰�
    }

    // �̸� ������ ����
    Name(students);

    // ���ĵ� �л� ����Ʈ ���
    Print(students);

    return 0;
}