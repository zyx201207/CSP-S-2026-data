#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const int maxn=500005;
int vis[maxn];
int a[maxn];
int b[maxn];
int p[maxn];
int n,m;
int cnt;
bool checkA(){
	for(int i=1;i<n;i++) if(a[i]>a[i+1]) return false;
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(checkA()){
		for(int i=1;i<=n;i++) p[a[i]]=i;
		for(int i=1;i<=m;i++) cout<<p[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) p[j]=0;
		cnt=0;
		for(int j=i;j<=n;j++){
			if(!p[a[j]]){
				b[++cnt]=a[j];
				p[a[j]]=cnt;
			}
			else cnt=p[a[j]];
		}
		for(int j=1;j<=cnt;j++) vis[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<vis[i]<<" ";
	return 0;
}
