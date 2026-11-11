#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005];
char c[100005];
int l[100005];
int r[100005];
int ls=0,ans=0;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;  
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];l[i]=ls+1;
		ls+=a[i];r[i]=ls;
	}
	double zhong=ls*1.0/2+0.5;
	for(int i=1;i<=n;i++)
	    for(int j=i+1;j<=n;j++)
		if(c[i]!=c[j]){
	    	double jui1=zhong-r[i];
	    	double juj1=l[j]-zhong;
	    	double jui2=zhong-l[i];
	    	double juj2=r[j]-zhong;
	    	double ll=max(jui1,juj1);
	    	double rr=min(jui2,juj2);
	    	int jia=rr-ll+1;jia=max(jia,0ll);
	    	ans+=jia;
		}
	cout<<ans;
	return 0;
}



/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b



*/





