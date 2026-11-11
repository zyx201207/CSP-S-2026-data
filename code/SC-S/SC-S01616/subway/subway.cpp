#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=500001;
int w[N];
int k[501];
int a[501][100001];
int t[501][100001];
int x[100001],y[100001];
int ans[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
		    ans[i]=w[x[i]]+w[y[i]];	
		}
	    for(int i=1;i<=n;i++){
		    for(int j=x[i];j<=y[i];j++){
			    ans[i]+=t[i][j]; 
		    } 
	    }
		cout<<ans;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}