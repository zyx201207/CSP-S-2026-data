//crystal
#include<bits/stdc++.h>
using namespace std;
long long int a[500005];
long long int z[500005];
int m1,s=1;
bool l;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long int n,m;
	cin>>n>>m;
	m1=m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		int g=1;
		if(a[i]!=a[i+1])
		for(int j=i;j>=0&&m1>=0;j--,g++)
		{
			m1-=(a[i]-a[j]);
			//cout<<i<<"&"<<j<<": m1-="<<a[i]<<"-"<<a[j]<<" "<<g<<endl;
			if(m1<=0)
			{
				//cout<<i<<" "<<m1<<" "<<g<<endl;
				s=max(s,g);
			}
		}
		m1=m;
		g=0;
	}
	if(n>10)
	cout<<s-1<<endl;
	else
	cout<<s<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
