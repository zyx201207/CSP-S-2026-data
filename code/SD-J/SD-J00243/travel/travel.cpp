#include <iostream>
#include <cstdio>
#include <bits/stdc++.h> 
using namespace std;

const int N = 1e1 + 1;

int ans[N];

string c1;
string s1;
string c2;
string s2;

int is_num(char ch)
{
	if(ch >= '0' && ch <= '9')
	{
		return 1;
	}
	
	return 0;
}

int get_num(string s)
{
	int res = 0;
	
	for(int i = 0; i < s.size(); i++)
	{
		if(is_num(s[i]) == 0)
		{
			return res;
		}
		
		res *= 10;
		res += int(s[i] - 0);
	}
	
	return res;
}

int check(char ch1, char ch2)
{
	if(ch1 >= 'D') // DF
	{
		if(ch2 >= 'D')
		{
			return 1;
		}
		
		return 0;
	}
	else // ABC
	{
		if(ch2 <= 'C')
		{
			return 1;
		}
		
		return 0;
	}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out ", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
	
	char ch1 = '0';
	char ch2 = '0';
	
	int num1 = 0;
	int num2 = 0;
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	ans[1] = 0;
	ans[2] = 0;
	ans[3] = 0;
	ans[4] = 0;
	
	if(c1 == c2) // 同一节车厢 
	{
		ans[1] = 1;
		
		num1 = get_num(s1);
		num2 = get_num(s2);
		
		if(num1 == num2) // 同一排
		{
			ans[2] = 1;
			
			ch1 = s1[2];
			ch2 = s2[2];
			
			if(check(ch1, ch2) == 1) // 同一侧
			{
				ans[3] = 1;
				
				if( abs( int(ch2) - int(ch1) ) == 1)
				{
					ans[4] = 1;
				}
			}
		} 
	}
	
	for(int i = 1; i <= 4; i++)
	{
		cout << ans[i];
	}
	cout << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
