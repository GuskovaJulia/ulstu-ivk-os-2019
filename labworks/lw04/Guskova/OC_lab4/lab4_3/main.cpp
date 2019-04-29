#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
//������������ ������ �4.3
//������������� �������������� ����� ����� pipe.
//��������� ��������� ��.�����-22 �������� �.�.
using namespace std;
int main()
{
    printf("������������ ������ �4.3\n");
    printf("������������� �������������� ����� ����� pipe\n");
    printf("��������� ��������� ��.�����-22 �������� �.�.\n");
    printf("�������: �������� ��������� ��� ����������� ������� ������ � ������������ ������������ �������.\
            ������, ��� ��� ������� ������ � �����,� ������� ��� �����, ��������� ����� write ���������� � �������.\n");
	int fd[2], result;//fd[0]-����� ������� �������� ����������, �����. �������� ������ ������ ������
                        //� ����������� ��������� ������ �������� ������
                       //fd[1] - ����� ������� �������� ����������, ���������������
                     //��������� ������ ������ � ����������� ��������� ������ �������� ������
	size_t size;
	pipe(fd);
	result = fork();
	if (result > 0)
	{//�������� ������������ �������
		int buf = 0;
		close(fd[0]);//��������� ����� ������ ������
		while (1)
		{ // �������� � ����������� ����� ���������� �� 1 ����� � �����
			buf++;
			size = write(fd[1],"", 1);
			printf("%d ���� \n ", buf); //������ ������ � ������������ ������������ �������
		}

		close(fd[1]);//��������� ����� ������ ������
	}
	else
	{//�������� �������� �������
		close(fd[1]);//��������� ����� ������ ������
		while (1); // ������� ������ �� ������ �� ������ ������
		close(fd[0]);//��������� ����� ������ ������
	}
	return 0;
}
