#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int ans[M];
int pos[N];
int nxt[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(pos[a[i]]){
			nxt[pos[a[i]]]=i;
		}
		pos[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int p=i;
		while(p<=n){
			if(nxt[p])p=nxt[p];
			else{
				ans[a[p]]++;
				p++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
