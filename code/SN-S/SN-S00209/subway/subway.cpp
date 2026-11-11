#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int ans[100005];
int w[100005];
int k[100005];
int a[100005];
int t[100005];
int x[100005];
int y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i]>>t[i];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<q;i++){
		for(int f=0;f<k[i];f++){
			if(a[i]==x[i]){
				for(int g=0;g<k[i];g++){
					if(a[g]==y[i]){
						for(int v=i;v<=g;i++){
							if(v!=g)
							ans[i]+=(t[v]+w[v]);
							else ans[i]+=t[v];
						}
			}
			}
		}
}
	}
	for(int i=0;i<q;i++){
		cout<<ans[q]<<endl;
	}
	return 0;
}
