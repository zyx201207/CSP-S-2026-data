#include<bits/stdc++.h>
using namespace std;
const int N = 200005; 
int n;
int c[N];
int k[20][20];
bool search(int m,int line)
{
	for(int i = 0;i < n; i++){
		if(k[i][line] == 1)
		{
			m--;
			if(m <= 0)
			{
				return true;
			} 
		}
	}
	if(m > 0)return false;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,j,len = 0;
	int res = 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> c[i];
		int a = c[i]; 
		j = 0;
		while(a > 1)
		{
			k[i][j] = a % 2;
			a/=2;
			j++;
		}
		k[i][j] = a;//存储数据
		len = max(len,j);
	}
	int key = -2;
	
	cout<<c[len];
	return 0;
}