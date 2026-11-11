#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005][35],l,r,wei[35];
int c(int x){
	memset(wei,0,sizeof wei);
	int cnt=0,kk=0;
	while(x){
		if(x&1)wei[kk]++;
		x>>=1;
		kk++;
	}
	for(int i=1;i<=n;i++){
		int flag=1;
		for(int j=33;j>=0;j--){
			if((wei[j]==1)&&(a[i][j]==0)){
				flag=0;
				break;
			}
		}
		cnt+=flag; 
	}
	if(cnt>=m)return 1;
	return 0;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		r=max(r,x);
		int k=0;
		while(x){
			if(x&1)a[i][k]++;
			x>>=1;
			k++;
		}
	}
	while(l<r){
		int mid=(l+r+1)/2;
		if(c(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
