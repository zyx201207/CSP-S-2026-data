#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[10000005],k[500005],a[10000][10000],t[10000][10000],x[10000005],y[10000005],mint[10000005];
void abc(int xx){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==xx){
				for(int y=1;y<=k[i];y++){
					long long minat=mint[xx]+t[i][j]+t[i][y];
					if(min(mint[a[i][y]],minat)==minat&&mint[a[i][y]]!=minat){
						mint[a[i][y]]=minat;
						abc(a[i][y]);
					}
				}
			}
		}
	}
}
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
		for(int j=1;j<=m;j++){
			mint[j]=100000000;
		}
		mint[x[i]]=0;
		abc(x[i]);
		cout<<mint[y[i]]+w[x[i]]+w[y[i]]<<endl;
	}
	return 0;
}