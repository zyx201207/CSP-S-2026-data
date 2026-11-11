#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+10;
int n,m,q;
int a[N];
int flag[N];	// is fail 
int fj[N][40];
int res[N];
int maxni=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		flag[i]=1;
		int nowi=0;
		while(a[i]){
			fj[i][nowi]=(a[i]&1);
			a[i]/=2;
			nowi++;
		}
		maxni=max(maxni,nowi);
	}
	for(int j=maxni;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(fj[i][j]==1&&flag[i]==1){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(fj[i][j]==0){
					flag[i]=0;
				}
			}
			res[j]=1;
		}
	} 
	int ans=0;
	for(int j=0;j<=maxni;j++){
		if(res[j]) ans|=(1<<j);
	}
	cout <<ans;
	return 0;
}

