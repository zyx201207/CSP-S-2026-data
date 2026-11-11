#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],t[N];
int ans,cnt,n,m;
void dfs(int num,int cnt){
	if(num==m){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(t[i]==0){
			int k=cnt;
			cnt=int(cnt&a[i]);
			t[i]=1;
			dfs(num+1,cnt);
			t[i]=0;
			cnt=k;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    for(int i=1;i<=n;i++){
    	cnt=a[i];
    	t[i]=1;
    	dfs(1,cnt);
    	t[i]=0;
	}
	cout<<ans;
	return 0;
}
