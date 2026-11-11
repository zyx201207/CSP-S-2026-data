#include<bits/stdc++.h>
using namespace std;
int n,s,ans,a=100000;
char c[200005];
long long sum[200005];
string ch;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sum[i]>>c[i];
	}
	if(n==1){cout<<0;return 0;}
	if(n==2){
		if(c[1]==c[2])cout<<0;
		else cout<<min(sum[1],sum[2]);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[i]>=a){
			sum[i]/=a;
		}else a=1;
		for(int j=1;j<=sum[i];j++)ch+=c[i];
	}
	s=ch.size();
	int ss=s;
	if(s%2==0)s/=2;
	else s=s/2+1;
	for(int i=1;i<=s;i++)
	{
		if(ch[i]!=ch[ss-i+1])ans+=1*a;
	}
	cout<<ans;
	return 0; 
 } 
