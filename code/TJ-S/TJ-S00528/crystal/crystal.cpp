#include <bits/stdc++.h>
using namespace std;

long long n,m,f;
long long num[500010];
int num_s[500010],s;
bool cmp (int a,int b){
	return a > b;
}

int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> num[i];
	}
	sort (num + 1,num + 1 + n,cmp);
	for(int i = 1;i <= n;i++)
	{
		f = m;
		for(int j = i;j <= n;j++)
		{
			f = f - num[i] + num[j];
			if (f >= 0)
			{
				num_s[i]++;
			}
			else
			{
				break;
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		s = max(s,num_s[i]);
	}
	cout << s;
	
	return 0;
}
