#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q,ans,w[500],k[500],x[100005],y[100005],a[10005][10005],s[10005][10005];
void f(int z,int b){
	for(int j=1;j<=k[z];j++){
		if(a[z][j]==b){
			ans=min(ans,s[z][j]+w[a[z][j]]);
		}
	}
}
void f2(int z,int b){
	for(int j=1;j<=k[z];j++){
		if(a[z][j]==b){
			q=min(q,s[z][j]+w[a[z][j]]);
		}
	}
}
void f3(int z,int b){
	for(int j=1;j<=k[z];j++){
		if(a[z][j]==b){
			ans=min(ans,s[z][j]+w[a[z][j]]+q);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>s[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		ans=1e18;
		ans+=w[x[i]];
		for(int j=1;j<=n;j++){
			for(int e=1;e<=k[j];e++){
				if(a[j][e]==x[i]){
					f(j,y[i]);
					if(j!=n){
						f2(j+1,a[j][e]);	
					}
					f3(j+1,y[i]);
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}