#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N];
bool used[300005];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		for(int j=i;j<=n;j++){
			if(!used[a[j]]){
				ans[a[j]]++;
				used[a[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}