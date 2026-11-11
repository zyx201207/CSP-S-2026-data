#include<bits/stdc++.h>
using namespace std;
#define zhr ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int N = 5e5+5 , M = 3e5+5;
int n,m;
int a[N];
int la[M];
int last[N];
int net[N];
int cnt[N];
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	zhr;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[i] = la[a[i]];
		la[a[i]]=i;
	}
	for(int i=1;i<=m;i++) la[i]=0;
	for(int i=1;i<=n;i++){
		net[la[a[i]]]=i;
		la[a[i]]=i;
	}
	for(int k=1;k<=n;k++){
		int i=k;
		memset(vis,0,sizeof vis);
		while(i<=n){
			if(!vis[a[i]]) {
				vis[a[i]]=1;
				cnt[a[i]]++;
			}
			if(net[i]!=0){
				i=net[i];
			}
			else i++;
			
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
