#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],d;
bool cmp(long long qwert,long long qwerty){
	return qwert>qwerty;
}
long long qw(long long v,long long b,long long censhu){
	if(a[b]-a[v]<d)return 1;
	long long mn=2147483647;
	if(censhu==1){
		long long ans=0,cg;
		for(long long i=v;i<b;i++){
			cg=qw(i,b,censhu+1);
			if(cg+1<mn){
				ans=0;
			}
			if(cg+1==mn){
				ans++;
			}
		}
		return ans;
	}
	for(long long i=v;i<b;i++){
		mn=min(qw(i,b,censhu+1),mn);
	}
	return mn+1;
}
int qwer(){
	cin>>n>>d;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long as;
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++)if(qw(i,j,1)==2)as++;
    }
	cout<<as;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		qwer();
	}
	return 0;
}
