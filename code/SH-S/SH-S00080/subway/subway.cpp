#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],t[500010][510],x,y,a,jilu1,jilu2,ans,tot,minn=INT_MAX;
int cc(int x1,int y1,int tot1){
	if (x1==y1){
		return tot1;
	}
	int tot2;
	for (int i=1;i<=n;++i){
		tot2=t[x1][i];
		if (t[x1][i]!=0){
			for (int j=1;j<=m;++j){
				if (t[j][i]!=0){
					tot2+=t[j][i];
					cc(j,y1,tot1+tot2);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;++i){
		cin>>w[i];
	}
	for (int i=1;i<=n;++i){
		cin>>a;
		for (int j=1;j<=a;++j){
			cin>>jilu1>>jilu2;
			t[jilu1][i]=jilu2;
		}
	}	
	for (int i=1;i<=q;++i){
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		for (int j=1;;++j){
			tot=0;
			int jilu=cc(x,y,tot);
			if (jilu<minn){
				minn=jilu;
			}
		}
		ans+=minn;
		cout<<ans;
	}
	return 0;
}
