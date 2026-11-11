#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
char a[21][41];
long long score=0;
void s(long long n)
{
	Sleep(n*1000);
}
void cls()
{
	system("cls");
}
void out()
{
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=40;j++)
		{
			cout<<a[i][j];
		}
		cout<<'\n';
	}
	cout<<"score:"<<score<<'\n';
}
int main()
{
	srand(time(NULL));
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=40;j++)
		{
			long long r=rand()%100;
			if(r<=5) a[i][j]='+';
			else if(r==7) a[i][j]='0';
			else a[i][j]='|';
		}
	}
	a[10][20]='U';
	out();
	while(1)
	{
		char c=_getch();
		if(c=='w')
		{
			if(a[9][20]=='+') continue;
			if(a[9][20]=='0') score++;
			cls();
			for(int i=20;i>1;i--)
			{
				for(int j=1;j<=40;j++)
				{
					if(a[i-1][j]=='U') a[i-1][j]='|';
					a[i][j]=a[i-1][j];
				}
			}
			for(int j=1;j<=40;j++)
			{
				long long r=rand()%100;
				if(r<=5) a[1][j]='+';
				else if(r==7) a[1][j]='0';
				else a[1][j]='|';
			}
			a[10][20]='U';
			out();
		}
		else if(c=='s')
		{
			if(a[11][20]=='+') continue;
			if(a[11][20]=='0') score++;
			cls();
			for(int i=1;i<=20;i++)
			{
				for(int j=1;j<=40;j++)
				{
					if(a[i+1][j]=='U') a[i+1][j]='|';
					a[i][j]=a[i+1][j];
				}
			}
			for(int j=1;j<=40;j++)
			{
				long long r=rand()%100;
				if(r<=5) a[20][j]='+';
				else if(r==7) a[20][j]='0';
				else a[20][j]='|';
			}
			a[10][20]='U';
			out();
		}
		else if(c=='d')
		{
			if(a[10][21]=='+') continue;
			if(a[10][21]=='0') score++;
			cls();
			for(int j=1;j<=39;j++)
			{
				for(int i=1;i<=20;i++)
				{
					if(a[i][j+1]=='U') a[i][j+1]='|';
					a[i][j]=a[i][j+1];
				}
			}
			for(int i=1;i<=20;i++)
			{
				long long r=rand()%100;
				if(r<=5) a[i][40]='+';
				else if(r==7) a[i][40]='0';
				else a[i][40]='|';
			}
			a[10][20]='U';
			out();
		}
		else if(c=='a')
		{
			if(a[10][19]=='+') continue;
			if(a[10][19]=='0') score++;
			cls();
			for(int j=40;j>1;j--)
			{
				for(int i=1;i<=20;i++)
				{
					if(a[i][j-1]=='U') a[i][j-1]='|';
					a[i][j]=a[i][j-1];
				}
			}
			for(int i=1;i<=20;i++)
			{
				long long r=rand()%100;
				if(r<=5) a[i][1]='+';
				else if(r==7) a[i][1]='0';
				else a[i][1]='|';
			}
			a[10][20]='U';
			out();
		}
	}
	return 0;
}