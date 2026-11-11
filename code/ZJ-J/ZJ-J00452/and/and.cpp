#include<bits/stdc++.h>
using namespace std;
long long mi[31];
long long n,m,a[200001];
long long yu(long long a,long long b){
	long long r=0;
	for(int i=31;i>=0;i--){
		if(a>=mi[i] and b>=mi[i])r+=mi[i],a-=mi[i],b-=mi[i];
		else if(a>=mi[i])a-=mi[i];
		else if(b>=mi[i])b-=mi[i];
	}
	return r;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long mx=-100;
	mi[0]=1;
	for(int i=1;i<=31;i++)mi[i]=mi[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)mx=max(mx,yu(a[i],a[j]));
			}
		}
		cout<<mx;
	}
	else if(m==n){
		mx=a[1];
		for(int i=2;i<=n;i++){
			mx=yu(a[i],mx);
		}
		cout<<mx;
	}
	else {
		for(int i=1;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx;
	}
	return 0;
}