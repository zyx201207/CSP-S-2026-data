#include<iostream>
#include<vector>
using namespace std;
#define int long long
int c;
struct pth{int l,t;};
void sol(){
	int n,d,res=0;
	cin>>n>>d;
	vector<int> a(n);
	vector<vector<pth> > dis(n,vector<pth>(n,{(int)1e9,0}));
	for(auto &i:a)
		cin>>i;
	for(int i=0;i<n;i++)
		dis[i][i]={0,1};
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			if(a[j]-a[i]>d)
				break;
			dis[i][j]={1,1},dis[j][i]={1,1};
		}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(i==k||k==j)
					continue;
				if(dis[i][k].l+dis[k][j].l<dis[i][j].l)
					dis[i][j]={dis[i][k].l+dis[k][j].l,1};
				else if(dis[i][k].l+dis[k][j].l==dis[i][j].l)
					dis[i][j].t++;
			}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(dis[i][j].t==2)
				res++;
	cout<<res<<"\n";
	//我已急哭，本来都写对了大部分了，然后给我一通改改错了，原本的还没保存T_T
	//现在都找不出哪里错了
	//感觉自己好弱智啊
	//我已高兴飞，调回来了啊哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈
	//能对一部分就不要去动了
}
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	int t;
	for(cin>>c>>t;t--;sol());
	return 0;
}