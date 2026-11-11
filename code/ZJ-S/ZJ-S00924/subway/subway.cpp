#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505],a[505][500005],t[505][500005];
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	map<int,int> e;
	map<int,int> re;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		e[a[i][1]]=i;
		e[a[i][2]]=i;
		re[i]=a[i][1];
		re[i]=a[i][2];
	}
	for(int i=1;i<=q;i++){
		e.clear();
		re.clear();
		cin>>x>>y;
		int ans=0;
		if(c>=7&&c<=11){
			ans+=w[x];
			while(x!=y){
				ans+=t[x][x];
				int lstx=x;
				for(int i=0;i<re.size();i++){
					if(re[i]==x){
						x=i;
					}
				}
				ans+=t[lstx][x];
			}
			ans+=w[y];
			cout<<ans<<"\n";
		}		
	}

	return 0;
}
/*
zhetitamadaodiheyiwei
zenmeraolairaoqude 
made
RP++
RP来
RP来
RP来
RP来
RP来
RP来
RP来
RP来
RP来
RP来
RP来
RP来
RP来
RP来
RP来
RP来
RP来
//freopen
feropen

*/
