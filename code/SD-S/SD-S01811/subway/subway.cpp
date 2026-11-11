#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010],k[510];
int qwe[500010][510];
int asd(int a,int b,int c,int d){
	if(a==b){
		d=min(c,d);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(qwe[j][i]){
				qwe[j][i]=-1;
				asd(j,b,c+2*qwe[j][i],d);
			}
		}
	}
	return d;
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
			int a,t;
			cin>>a>>t;
			qwe[j][i]=t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,ans=0;
		cin>>x>>y;
		ans+=(w[x]+w[y]);
		//ans+=asd(x,y,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/
