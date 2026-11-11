#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[500010],s[300010],nxt[500010];
ll t[500010],ans[300010];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--){
		nxt[i]=s[a[i]];
		s[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		t[i]++;
		if(nxt[i]==0) ans[a[i]]+=t[i];
		if(i<n){
			if(nxt[i]==0){
				t[i+1]+=t[i];
			}
			t[nxt[i]]+=t[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
