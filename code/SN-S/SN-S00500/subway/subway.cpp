//SN-S00500 高梓焱 西安市第三中学 
#include<bits/stdc++.h>
using namespace std;
struct e{
	int k;
	int t[1000];
};
e a[10000];
int c,n,m,d,q,w[10000],b[1000][10000],k,h[1000][1000],now;
int l(int x,int y){
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].k;j++){
			if(a[i].t[j]==x){
				int now=i;
			}
			for(int ij=0;ij<a[i].k;ij++){
				if(a[i].t[j]==x&&a[i].t[ij]==y){
					return w[x]+w[y]+b[i][j]+b[i][ij];
				}
			}
		}
	}
	for(int i=0;i<a[now].k;i++){
		for(int j=0;j<n;j++){
			if(h[a[now].t[i]][j]>n){
				return b[now][i]+b[j][a[j].t[i]]+l(i,y);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>a[i].k;
		for(int j=0;j<k;j++){
			cin>>a[i].t[j]>>b[i][j];
			h[a[i].t[j]][i]=1;
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		cout<<l(x,y)<<endl;
	}
	return 0;
}
