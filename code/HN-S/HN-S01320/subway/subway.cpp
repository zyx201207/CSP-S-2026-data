#include<bits/stdc++.h>
using namespace std;
int ww[500005],t[500005][505],vf[500005],k[505];vector<int>v[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int w,z;cin>>w>>z;
			v[i].push_back(w);
			t[w][i]=z;
			vf[w]=i;
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;int ll=vf[l],rr=vf[r];
		cout<<ww[l]+ww[r]+t[l][ll]+t[r][rr]<<endl; 
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2



