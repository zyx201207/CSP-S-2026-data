#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	char c[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long int ssum=0;
	for(int i=1;i<=n;i++)
	{
		ssum+=a[i];
	}
	ssum/=2;
	int m=0,p=0;
	while(ssum>0)
	{
		m++;
		if(ssum<a[m]) p=ssum;
		if(ssum==a[m]){
			ssum-=a[m];
			m++;
		}
		else ssum-=a[m];
	}
	stack<char> s;
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<=a[i];j++){
			s.push(c[i]);
		}
	}
	for(int i=1;i<=p;i++)
	{
		s.push(c[m]);
	}
	int cnt=0;
	int q=0;
	for(int i=1;i<=n;i++){
		q+=a[i];
	}
	q=q/2+1;
	int zzz=0;
	while(q>0){
		zzz++;
		q-=a[zzz];
		if(q==0) zzz++;
	}
	if(a[m]-p==0&&a[m+1]==1) p=1;
	else if(a[m]-p==0&&a[m+1]!=1) p=2;
	else if(a[m]-p==1) p=1;
	else p+=2;
	for(int i=p;i<=a[zzz];i++)
	{
		if(c[zzz]==s.top()) s.pop();
		else{
			cnt++;
			s.pop();
		}
	}
	for(int i=zzz+1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			if(c[zzz]==s.top()) s.pop();
			else{
				cnt++;
				s.pop();
			}	
		}
	}
	cout<<cnt;
	return 0;
}
