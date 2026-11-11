#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],p,cnt=INT_MIN;
int check(int M){
	int r=0,p=0;
	for(int i=1;i<=n;i++)
		if(a[i]<=M)r+=M-a[i],p++;
	return (r<=m?p:-1);
} 
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int l=LLONG_MAX,r=LLONG_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	while(l<r){
		int M=(l+r)/2;
		int q=check(M);
		if(q!=-1)l=M+1,cnt=max(cnt,q);
		else r=M;
	}
	cout<<cnt;
	return 0;
}//这题还行 50 ~ 90pts 16:30 
