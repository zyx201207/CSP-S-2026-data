#include<bits/stdc++.h>
using namespace std;
const int M=3e5+10;
const int N=5e5+10;
bool vis[M];
vector<int> cur;
int cunt[M];
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int start=1;start<=n;start++){
		cur.resize(0);
		memset(vis,0,sizeof(vis));
		for(int i=start;i<=n;i++){
			if(vis[a[i]]){   
				for(int j=cur.size()-1;j>=0;j--){
					if(cur[j]==a[i]) break;
					vis[cur[j]]=0;
					cur.pop_back();
				}
			}
			else{
				vis[a[i]]=1;
				cur.push_back(a[i]);
			}
		}
		for(int y=0;y<cur.size();y++){
			int kq=cur[y];
			cunt[kq]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cunt[i]<<" ";
	}
	return 0;
}
