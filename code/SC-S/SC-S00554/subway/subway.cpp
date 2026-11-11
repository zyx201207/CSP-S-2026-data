#include<bits/stdc++.h>
using namespace std;
const int N=505;
int c,n,m,d,q;
int w[N],a[100010][N],s[N][N],ml[N][N],qa[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=100000;j++){
			a[j][i]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=n;i++){
		long long k,tt,ttt;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>tt>>ttt;
			a[tt][i]=ttt;
			if(qa[tt]==0)qa[tt]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int l=j;l<=n;l++){
				if(l==j){
					s[l][j]=0;
				}
				s[j][l]=min(s[j][l],a[i][j]+a[i][l]);
				s[l][j]=min(s[l][j],a[i][j]+a[i][l]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				s[j][l]=min(s[j][l],a[i][j]+a[i][l]);
			}
		}
	}
	while(q--){
		int st,en;
		cin>>st>>en;
		cout<<s[qa[st]][qa[en]]+w[st]+w[en];
	}
	return 0;
}