#include<bits/stdc++.h>
using namespace std;
int a[500010];
int p[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
             int b,c;
             cin>>b>>c;
             p[j]=c;
		}
	}
	for(int i=1;i<=q;i++){
	    int x,y;
	    cin>>x>>y;
	    cout<<a[x]+a[y]+p[x]+p[y]<<endl;
	}
	return 0;
}