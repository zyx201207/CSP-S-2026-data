#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+5;
int a[N],n,m,s[N];
bool f[N];
int xb[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	for(int k = 1;k<=n;k++){
		memset(f,0,sizeof(f));
		memset(xb,0,sizeof(xb));
		queue<int> q;
		for(int i = k;i<=n;i++){
			if(f[a[i]] == 1){
				int l = q.size(),x;
				queue<int> w;
				bool g = 0;
				for(int j = 1;j<=l;j++){
					if(q.front() == a[i]&&g == 0) g = 1,x = j-1;
					w.push(q.front());
					q.pop();
				}
				for(int j = x+1;j<=i;j++){
					f[a[j]] = 0;
					xb[a[j]] = 0;	
				}
				for(int j = x;j<=i;j++){
					f[a[j]] = 0;
					xb[a[j]] = 0;	
				}
				for(int j = 1;j<=x;j++) q.push(w.front()),w.pop();
			}
			q.push(a[i]);
			f[a[i]] = 1;
			xb[a[i]] = 1;
		}
		int l = q.size();
		for(int j = 0;j<l;j++) s[q.front()]++,q.pop();
	}
	for(int i = 1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
}
