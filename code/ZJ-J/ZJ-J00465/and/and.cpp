#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005][32],flag[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j=1;j<=30;j++){b[i][j]=x&1;x>>=1;}	
		
	}
	int ans=0;
	for(int i=1;i<=n;i++) flag[i]=1;
	for(int j=30;j>=1;j--){
		int cntw=0;
		for(int i=1;i<=n;i++){
			if(!flag[i]) continue;
			cntw+=b[i][j];			
		}
		if(cntw>=m){
			for(int i=1;i<=n;i++){
				if(b[i][j]!=1) flag[i]=0;
			}
			ans+=(1<<j-1);
		}
	}
	cout<<ans;
	return 0;
}
