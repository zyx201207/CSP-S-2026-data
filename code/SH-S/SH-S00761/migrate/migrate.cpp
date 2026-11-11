//1
#include<bits/stdc++.h>
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
using namespace std;
const int MAXN=2000200;
int c,t,n,d,x[MAXN],v[MAXN],ans;
vector<vector<int>> nxt;
int len[MAXN],cnt[MAXN];
queue<int> q;
bool f[MAXN];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(f,0,sizeof(f));
		nxt.assign(n+5,vector<int>());
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		sort(x,x+n);
		for(int i=0,j=0;i<n;i++){
			if(x[i]-x[j]>d){
				j++;
			}
			for(int k=j;k<i;k++){
				nxt[k].push_back(i);
			}
		}
		ans=0;
		for(int i=0;i<n;i++){
			while(!q.empty())q.pop();
			memset(len,0,sizeof(len));
			memset(cnt,0,sizeof(cnt));
			q.push(i);
			len[i]=0;
			while(!q.empty()){
				int temp=q.front();
				q.pop();
				for(auto &y:nxt[temp]){
					if(!f[y]){
						q.push(y);
						if(len[y]!=0){
							if(len[temp]+1==len[y])cnt[y]++;
							else if(len[temp]+1<len[y]){
								cnt[y]=1;
								len[y]=len[temp]+1;
							}
						}
						else{
							cnt[y]=1;
							len[y]=len[temp]+1;
						}
					}
				}
				f[temp]=1;
			}
			for(int j=0;j<n;j++){
				if(cnt[j]==2)ans++;
			}
		}
		

		cout<<ans<<endl;
	}
	return 0;
}
