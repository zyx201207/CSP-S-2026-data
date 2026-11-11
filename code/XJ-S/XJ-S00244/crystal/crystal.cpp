#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
const int N=5e5+10;
long long a[N],pre[N];
bool flag1,flag2;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		pre[i]=abs(a[i]-a[i-1]);
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		pre[i]=abs(a[i]-a[i-1]);
	}
	pre[1]=N;
	//long long cnt=0,sum=0,t=0;
	//AÌØÅÐ
	for(int i=1; i<=n; i++) {
		if(a[i]!=i)flag1=1;
	}
	if(flag1==0) {
		long long LG=0;
		for(int i=1; i<=n; i++) {
			LG+=i;
			if(LG+i+1>m) {
				cout<<i+1;
				return 0;
			}
		}
		cout<<n;
	}
	//BÌØÅÐ
	for(int i=3; i<=n; i++) {
		//cout<<pre[i]<<" ";
		if(pre[i]!=pre[i-1])flag2=1;	
	}
	if(flag2==0&&pre[2]!=0) { 
		long long LG=0;
		for(int i=1; i<=n; i++) {
			LG+=i*pre[2];
			//cout<<"LG:"<<LG<<"\n"; 
			if(LG+i+1>m) {
				cout<<i+1;
				return 0;
			}
		}
		cout<<n;
	}
	//±©Á¦
	for(int i=2;i<=n;i++){
		long long LG=0,cnt=0,t=1;
		for(int j=i;j<=n;j++){
			if(LG+t*pre[j]>m)break;
			LG+=t*pre[j];
			//cout<<pre[j]<<"\n"; 
			cnt++;
			t++;
		}
		ans=max(ans,cnt+1);
	} 
	cout<<ans;
	return 0;
}
