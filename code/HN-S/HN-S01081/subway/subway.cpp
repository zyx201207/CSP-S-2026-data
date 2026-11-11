#include<bits/stdc++.h>

using namespace std;

const int N=205;

struct Node{
	int to,vl;
};

int n,m,d,q;

int a[N][500005],v[500005],t[N][500005],is[500005],k[500005],fa[500005];
vector<Node>vec[N];
set<int>st;

int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int c;
	
	cin>>c>>n>>m>>d>>q;

	for(int i=1;i<=m;i++){
		cin>>v[i];
		fa[i]=i;
		is[i]=0;
	}

	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(st.count(a[i][j])){
				is[a[i][j]]=1;
			}
			st.insert(a[i][j]);
			fa[a[i][j]]=fa[a[i][1]];
		}
	}
	
	while(q--){
		int x,y,t1=-1,t2=-1,t3;
		cin>>x>>y;
//		cout<<fa[x]<<' '<<fa[y];
		if((fa[x]==fa[y])){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==x){
						t1=t[i][j];
					}
					if(a[i][j]==y){
						t2=t[i][j];
					}
				}
				if(t1!=-1 && t2!=-1) break;
			}
			cout<<v[x]+v[y]+t1+t2<<endl;
			continue;
		}
		cout<<v[x]+v[y]+29;
	}
	return 0;
}
