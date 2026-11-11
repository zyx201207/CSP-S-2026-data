#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int w[MAXN],sta[MAXN],stan[MAXN]={0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(c<=6&&c>=1){
		int wei[55][55],ne[55][55],num[55]={0},dp[55];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			int a[55],t[55];
			for(int j=1;j<=k;i++){
				cin>>a[j]>>t[j];
			}
			for(int j=1;j<k;j++){
				for(int x=j+1;x<=k;x++){
					ne[a[j]][num[a[j]]+1]=a[k];
					num[a[j]]++;
					wei[a[j]][a[k]]=t[j]+t[k];
					ne[a[k]][num[a[k]]+1]=a[j];
					num[a[k]]++;
					wei[a[k]][a[j]]=t[j]+t[k];
				}
			}
		}
	} 
	else if(c>=12&&c<=19){
		for(int i=1;i<=n;i++){
			int k,t;
			cin>>k;
			for(int j=1;j<=k;j++){
				int a;
				cin>>a>>t;
			}
		}
		while(q--){
			int o,r;
			cin>>o>>r;
			cout<<w[o]+w[r]<<endl;
		}
	}
	return 0;
}
