#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
map<int,int>ans;
int n,m,a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int k = 1;k <= n;k++){
		map<int,int>mp;
		for(int i = k,j = k;j <= n;j++){
			if(mp[a[j]]){
				while(i != j){
					mp[a[i]]--;
					ans[a[i]]--;
					i++;
				}
			}
			mp[a[j]]++;
			ans[a[j]]++;
		}
		
	}
	for(int i = 1;i <= m;i++)cout<<ans[i]<<' ';
	return 0;
} 
