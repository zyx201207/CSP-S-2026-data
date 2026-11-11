#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[510];
vector<int>a[500010],t[500010];
struct node{
	int id,t;
};
vector<node>sta[500010];
int f[510][510];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
//    freopen("subway7.in","r",stdin);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
//    cout<<w[m]<<endl;
    for(int i=1;i<=n;i++){
    	cin>>k[i];
//    	a[i].push_back(0),t[i].push_back(0);
    	for(int j=1;j<=k[i];j++){
    		int aa,tt;
    		cin>>aa>>tt;
//    		a[i].push_back(aa),t[i].push_back(tt);
    		sta[aa].push_back({i,tt});
		}
	}
//	cout<<"---"<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i!=j)f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(node j:sta[i]){
			for(node k:sta[i]){
				if(j.id!=k.id){
					int ww=j.t+k.t;
					f[j.id][k.id]=f[k.id][j.id]=min(f[j.id][k.id],ww);
//					cout<<j.id<<" "<<k.id<<" "<<ww<<endl;
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
//		cout<<i<<" "<<x<<" "<<y<<endl;
		int res=1e18;
		for(node j:sta[x]){
			for(node k:sta[y]){
//				cout<<j.id<<" "<<k.id<<" "<<f[j.id][k.id]<<endl;
				res=min(res,f[j.id][k.id]+j.t+k.t);
			}
		}
		cout<<res+w[x]+w[y]<<'\n';
	}
    return 0;
}
/*
题目好长... 
不就是搞诈骗吗，问的就是两条线路之间的最小步行时间 
然后 Floyd 可以直接求出来 
但是这样 d 有什么用吗 
哦有用，这样可以预处理出来两两初始距离 
好神秘。 
此时开考 30min 读完所有题对三道图论（至少描述是这样）很无语 

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/