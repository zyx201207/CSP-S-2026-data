#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int w[N];
const int M = 500+10;
int k[M];
int a[M][M],t[M][M],tm[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(tm,0x3f3f3f3f,sizeof tm);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(tm[a[i][j]]>t[i][j]){
				tm[a[i][j]]=t[i][j];
			}
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		for(int i=l;i<=r;i++){
			sum+=tm[a[i][i]];
		}
		cout<<sum<<endl;
	}
	return 0;
}
