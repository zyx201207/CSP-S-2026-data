#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N],t[N],ans[N],f[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(t[a[i]]==0)
			f[a[i]]=i;
		t[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			if(t[a[j]]>1){
				ans[a[j]]++;
				if(f[a[j]]!=n){
					j=f[a[j]]+1;
				}
				else{
					break; 
				}
			}
			else{
				ans[a[j]]++;
				j++;
			}
		} 
		t[a[i]]--;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' '; 
	return 0;
}
