#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m;
struct node{
	int x;
	int ch[35];
}a[200005];
inline bool cmp(node xx,node yy){
	return xx.x<yy.x;
}
vector<int>V;
bool vis[200005]; 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		int k=a[i].x,xb=29;
		while(k){
			if(k%2==1){
				a[i].ch[xb]=1;
			}
			else{
				a[i].ch[xb]=0;
			}
			k/=2,xb--;
		}
		for(int j=0;j<=xb;j++){
			a[i].ch[j]=0;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=29;j++){
//			cout<<a[i].ch[j];
//		}
//		cout<<endl;
//	}
	int fromnow=0;
	for(int i=0;i<30;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			cnt+=a[j].ch[i];
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(a[j].ch[i]){
					V.push_back(j);
					vis[j]=1;
				}
			}
			fromnow=i;
			break;
		}
	}
	for(int i=fromnow;i<=29;i++){//从第 fromnow 逐步筛选
		//每一次选出第 i 位最大的 m 个 
		int cnt=0;
		for(int j=0;j<V.size();j++){
			if(vis[V[j]]){
				cnt+=a[V[j]].ch[i];
			}
		}
		if(cnt>=m){
			for(int j=0;j<V.size();j++){
				if(vis[V[j]]&&!a[V[j]].ch[i]){
					vis[V[j]]=0;
				}
			}
		}
	}
	int ans=(1<<30)-1,cnt=0;
	for(int i=0;i<V.size();i++){
		if(vis[V[i]]&&cnt<=m){
			ans&=a[V[i]].x;
			cnt++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
