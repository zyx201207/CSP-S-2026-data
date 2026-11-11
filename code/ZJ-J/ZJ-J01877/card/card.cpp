#include <iostream>
using namespace std;
const int maxn=5e5+10;
const int maxm=3e5+10;
int n,m;
int a[maxn];
int last[maxn],nxt[maxn];
int ans[maxm];
bool done[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nxt[last[a[i]]]=i;
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			done[a[j]]=true;
			if(nxt[j]!=0) j=nxt[j];
			else j++;
		}
		for(int k=1;k<=m;k++){
			if(done[k]) ans[k]++;
			done[k]=false;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
} 
