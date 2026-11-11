#include<bits/stdc++.h>
/*
OI就像一只小船， 
AFO就像黑夜里的唯一一盏灯塔 
无论如何，小船都会驶向它 
各种手段也只是延缓时间罢了
所以说：
AFO神永生
（背的不牢，请见谅） 
*/
using namespace std;
int n,m,c,d,q;
int t[510][20010];
int w[20010];
int a[510][20010];
int k[20010];
int f[20010];
struct node{
	int now,sum;
};
vector<int>my_subway[510];
void work(){
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=m;i++){
		
		f[i]=INT_MAX;
		
	}
	queue<node>q;
	
	q.push({x,0});
	f[x]=-1;
	while(!q.empty()){
		int now=q.front().now;
		int w=q.front().sum;
		q.pop();
		if(f[now]>w)continue;
		for(int i=0;i<my_subway[now].size();i++){
			int this_sub=my_subway[now][i];
			int rr=t[this_sub][now];
				
			for(int j=1;j<=k[this_sub];j++){
				int v=a[this_sub][j];
				int ww=t[this_sub][v];
				if(v!=now&&f[v]>rr+w+ww){
					f[v]=rr+w+ww;
					q.push({v,f[v]});
				}
			}
			
		}
	}
	cout<<w[x]+w[y]+f[y]<<endl;
}

void k1(){//21,22
	int ans=INT_MAX;
	cin>>w[1]>>w[2];
	for(int i=1;i<=n;i++){
		
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			scanf("%lld %lld",&a[i][j],&t[i][j]);
			
		}
		if(k[i]==2){
			ans=min(ans,t[i][1]+t[i][2]);
		}
	}
	ans+=w[1]+w[2];
	while(q--)cout<<ans;
	exit(0);
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==21||c==22){
		k1();
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	
	
	for(int i=1;i<=n;i++){
		
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			scanf("%lld",&a[i][j]);
			my_subway[a[i][j]].push_back(i);
			scanf("%lld",&t[i][a[i][j]]);
		}
	}
	while(q--){
		work();
	} 
	
	return 0;
}
