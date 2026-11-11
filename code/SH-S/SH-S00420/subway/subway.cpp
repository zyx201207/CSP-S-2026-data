#include<bits/stdc++.h>
using namespace std;
const int N=109;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,e,f[N],g[N],h[N][N],k[N][N],l[N],m[N];
	int o=0;
	int ans[N];
	cin>>a>>b>>c>>d>>e;
	for(int i=0;i<c;i++)
		cin>>f[i];
	for(int i=0;i<b;i++){
		cin>>g[i];
		for(int j=0;j<g[i];j++)
			cin>>h[i][j]>>k[i][j];
	}
	for(int i=0;i<e;i++)
		cin>>l[i]>>m[i];
	for(int i=0;i<b;i++)
		for(int j=0;j<g[i];j++){
			if(h[i][j]==m[o]){
				ans[o]+=k[i][j];
			}
			else
				ans[o]+=14;
			o++;
	 }
	for(int i=0;i<e;i++)
		ans[i]+=f[l[i]-1]+f[m[i]-1]+k[0][0];
	for(int i=0;i<e;i++)
		cout<<ans[i]<<endl;
	return 0;
}
