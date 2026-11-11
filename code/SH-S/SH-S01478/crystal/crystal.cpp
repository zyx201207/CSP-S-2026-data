#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long s[500009],q[500009];
bool ck(long long x){
	for(long long i=x;i<=n;i++){
		if((x-1)*s[i]-(q[i-1]-q[i-x])<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long l=1,r=n;
	for(long long i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(long long i=1;i<=n;i++){
		q[i]=q[i-1]+s[i];
	}
	
	long long mid=(l+r)/2;
	long long flg=0;
	while(l<r){
		//cout<<l<<" "<<r<<endl;
		if(mid==(l+r)/2) flg++;
		if(flg==5) break;
		mid=(l+r)/2;
		if(ck(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
