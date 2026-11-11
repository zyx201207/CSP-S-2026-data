#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[501][500005],k,f[5005][5005],x,y,a1,t1,a2,t2,ans[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k==1){
			cin>>x>>y;
		}else{
			cin>>a1>>t1>>a2>>t2;
			f[a1][a2]=t1+t2;
			f[a2][a1]=t1+t2;
		//	cout<<f[a1][a2]<<" "<<f[a2][a1]<<"----"<<endl;
		}
	}memset(ans,0x3f,sizeof(ans));
	ans[1]=0;
	for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(f[i][j]) ans[j]=min(ans[j],ans[i]+f[i][j]);
			}
	}
	while(q--){
		cin>>x>>y;
		if(x>y)swap(x,y);
		cout<<w[x]+w[y]+ans[y]-ans[x]<<"\n";
	}
	
	
	return 0;
}

