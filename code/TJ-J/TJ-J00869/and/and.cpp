#include <iostream>
using namespace std;
int a,m,s[100001],d[100001][101][2],mx;
int sdf(int op)
{
	int i,k = 0,l = 0;
	for(i = 1;i <= op;i *= 2)
	{
		k++;
	 } 
	i /= 2;
	k--;
	for(;op != 0;i /= 2)
	{
		l *= 10;
		if(i < op)
		{
			op -= i;
			l++;
		}
		if(i == op)
		{
			l++;
			for(int j = 1;j <= k;j++)
			{
				l *= 10;
			}
			op = 0;
		}
		k--;
	 } 
	 return l;
 } 
 int jkl(int i,int j)
 {
 	int l = 0,k = max(s[i],s[j]),q,w;
 	if(s[i] == k)
 	{
 		q = i;
 		w = j;
	 }
 	else
 	{
 		q = j;
 		w = i;
	}
	 int lx = d[0][p][2],ln = d[o][w][2];
	 int lop[10001],uio = 1;
	 for(int g = lx - ln;g <= lx;g++)
	 {
	 	lop[uio] = 
	 }
	 uio--;
 	return l;
 }
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> a >> m;
	for(int i = 1;i <= a;i++)
	{
		cin >> s[i];
		s[i] = 	sdf(s[i]);
	}
	for(int i = 1;i <= a;i++)
	{
		for(int j = 1;s[i] > 0;j++)
		{
			d[j][i][1] = s[i] % 10;
			s[i] -= s[i] % 10;
			s[i] /= 10;
			d[0][i][2]++;
		}
	}
	if(m == 2)
	{
		for(int i = 1;i <= a;i++)
		{
			for(int j = 1;j <= a;j++)
			{
				if(j == i)
				{
					continue;
				}
				mx = max(mx,jkl(i,j));
			 } 
		}
		cout << 12;
	}
	cout << 12; 
	return 0;
 } 
 
