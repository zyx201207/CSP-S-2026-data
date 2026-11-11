#include<bits/stdc++.h>
using namespace std;
int w[500005],k[500005],a[500001],t[500001],x[200005],y[200005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	long long minn=1000000001;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[j]>>t[j];
	}
	for(int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++){
		for(int j=1;j<=m;j++){
			if(t[x[i+j]]<minn && ){
				minn==w[x[i+j]];
			}
		}
	}
	return 0;
}
