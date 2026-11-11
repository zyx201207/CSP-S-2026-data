#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],sum[500010],p[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		p[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+p[i];
	}
	int l=1,r=1,s=0,pos=0,maxn=0;
	while(l<=r&&r<n){
		if(s+(pos+1)*p[r]<=m){
			s=s+(pos+1)*p[r];
			pos++;
			maxn=max(maxn,pos);
			r++;
			//cout<<l<<" "<<r<<" "<<s<<"\n";
		}else{
			s-=sum[r-1]-sum[l-1];
			l++;
			pos--;
		}
	}
	cout<<maxn+1;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
