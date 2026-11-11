#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
#define ll long long
int n,m;
int a[N],b[N];
queue<int> q;
ll ans[N];
bool fl=1;
/*
bool check(int x,int y,int p){
	for(int i=y-1;i>=p;i--){
		if(x==a[y]) return 0;
	}
	return 1;
}*/
void popp(int p,int r){
	for(int i=r-1;i>=1;i--){
		if(q.front()==p){
			b[a[i]]--;
			return;
		}
		q.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
			q.push(a[j]);
			if(b[a[j]]>0) popp(a[j],j);
			b[a[j]]++;
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]>0 && fl){
				ans[a[j]]++;
				fl=0;
			}
		}
		while(!q.empty()) q.pop();
		for(int j=1;j<=m;j++) b[j]=0;
		fl=1;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

