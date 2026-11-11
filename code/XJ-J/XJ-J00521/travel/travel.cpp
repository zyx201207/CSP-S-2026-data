#include <bits/stdc++.h>
using namespace std;
string c1;
string c2;
string s1;
string s2;
int answer = 10;
int main()
{
	ifstream fin ("travel.in");
	ofstream fout("travel.out");
	fin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		answer += 1000;
		if (s1[1] == s2[1] && s1[2] == s2[2]){
		answer += 100;
			if (s1[3] == 'A'||s2[3] == 'B')
			{
				answer += 10;
				if (s1[3] - s2[3] == 1|| s1[3] - s2[3] == -1)
				{
					answer += 1;
					fout << answer;
				}
				else
				{
					fout << "1110";
				}
			}
			else if (s2[3] == 'A'||s1[3] == 'B')
			{
				answer += 10;
				if (s1[3] - s2[3] == 1|| s1[3] - s2[3] == -1)
				{
					answer += 1;
					fout << answer;
				}
				else
				{
					fout << "1110";
				}
			}
			else if (s1[3] == 'A'||s1[3] == 'C')
			{
				answer += 10;
				if (s1[3] - s2[3] == 1|| s1[3] - s2[3] == -1)
				{
					answer += 1;
					fout << answer;
				}
				else
				{
					fout << "1110";
				}
			}
			else if (s2[3] == 'A'||s2[3] == 'C')
			{
				answer += 10;
				if (s1[3] - s2[3] == 1|| s1[3] - s2[3] == -1)
				{
					answer += 1;
					fout << answer;
				}
				else
				{
					fout << "1110";
				}
			}
			else if (s1[3] == 'B'||s1[3] == 'C')
			{
				answer += 10;
				if (s1[3] - s2[3] == 1|| s1[3] - s2[3] == -1)
				{
					answer += 1;
					fout << answer;
				}
				else
				{
					fout << "1110";
				}
			}
			else if (s1[3] == 'C'||s1[3] == 'B')
			{
				answer += 10;
				if (s1[3] - s2[3] == 1|| s1[3] - s2[3] == -1)
				{
					answer += 1;
					fout << answer;
				}
				else
				{
					fout << "1110";
				}
			}
			else if (s1[3] == 'D'||s1[3] == 'F')
			{
				answer += 10;
				if (s1[3] - s2[3] == 1|| s1[3] - s2[3] == -1)
				{
					answer += 1;
					fout << answer;
				}
				else
				{
					fout << "1110";
				}
			}
			else if (s1[3] == 'F'||s1[3] == 'D')
			{
				answer += 10;
				if (s1[3] - s2[3] == 1|| s1[3] - s2[3] == -1)
				{
					answer += 1;
					fout << answer;
				}
				else
				{
					fout << "1110";
				}
			}
			else
			{
				fout << "1100";
			}
		}
		else
		{
			fout << "1000";
		}
	{
	else{
		fout << "0000";
	}
	fin.close(); 
	fout.close();
	return 0;
}