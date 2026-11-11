#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int cnt[300005],ans[300005],hou[300005],n;
bool check(int j){
	memset(cnt,0,sizeof(cnt));
	for(int i=j;i<=n;i++){
		cnt[a[i]]++;
		if(cnt[a[i]]==2){
			return 0;
		}
	}
	return 1;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j])
				hou[i]=j;
		}
	}
	for(int i=1;i<=n;i++){
		int j=i;
		for( ;j<=n;j++){
			int x=hou[j];
			if(a[x]==a[j]){
				j=x-1;
			}else{
				if(check(j)||j==n){
					break;
				}else{
					ans[a[j]]++;
				}
			}
			
		}
		for(int k=j;k<=n;k++){
			ans[a[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
