#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m],k,a[n][2];;
	for(int i=0;i<m;i++) cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k;

		cin>>a[i][0]>>a[i][1];
	}
	int ans;
	for(int i=0;i<q;i++){
		cin>>x>>y;
		ans=w[x]+w[y];
		for(int i=0;i<n;i++){
		    if(a[i][0]==x || a[i][0]==y) ans+=a[i][1];
	    }
		cout<<ans;
	}
	return 0;
}
