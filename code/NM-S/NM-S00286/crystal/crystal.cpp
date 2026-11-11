#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m,a[N];
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
	cin>>a[i];
sort(a+1,a+1+n);
long long t=1;	
while(m>0)
{  
		long long h=0;
		if((a[t+1]-a[t])*t<=m) h=(a[t+1]-a[t]);
		else break;
		m-=h*t;
		for(int i=1;i<=t;i++)
			a[i]+=h;
		t++;
}
long long num=1,ans=0;
for(int i=1;i<=n;i++)
{
	if(a[i]==a[i+1]) num++;
	else 
	{
		if(num>=ans) {ans=num;num=1;}
		else num=1;
	}
}
cout<<ans<<endl;
fclose(stdin);
fclose(stdout);
return 0;
}
