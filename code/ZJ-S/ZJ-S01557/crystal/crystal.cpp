#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,ans=1,sum=0,maxn=0,t;
	cin>>n>>m>>t;
	if(abs(t)>2100000000){
		long long tt;
		cin>>tt;
		long long cha=abs(t-tt),s=0;
		for(int i=1;i<=n;i++){
			s+=i;
			if(m<s*cha){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	int a[500000];
	a[0]=int(t);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	sum=a[0];
	for(int l=0,r=1;r<n;r++){
		if(a[r]*(r-l)-sum<=m)ans++;
		else{
			maxn=max(ans,maxn);
			l++;
			sum-=a[l-1];
		}
		sum+=a[r];
	}
	maxn=max(ans,maxn);
	cout<<maxn;
	return 0;
}
