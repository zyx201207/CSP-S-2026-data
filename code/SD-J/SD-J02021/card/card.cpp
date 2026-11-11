#include<bits/stdc++.h>
using namespace std;
long long g[200005],cnt,n,m,a[200005],f[200005];
queue<long long>q;
bool check(long long key){
	for(int i=1;i<=cnt;i++){
		if(g[i]==key){
			return i;
		}
	}return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)q.push(a[j]);
		memset(g,0,sizeof(g));
		cnt=0;
		for(int j=i;j<=n;j++){
			long long t=q.front();
			q.pop();
			long long key=check(t);
			if(!key){
				g[++cnt]=t;
			}else{
				for(int k=key;k<=cnt;k++){
					g[k]=0;
				}cnt=key-1;
				g[++cnt]=t;
			}
		}for(int j=1;j<=cnt;j++){
			f[g[j]]++;
		}while(!q.empty())q.pop();
	}for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}
