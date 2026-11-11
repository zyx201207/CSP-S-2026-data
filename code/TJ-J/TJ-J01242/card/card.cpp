#include<bits/stdc++.h>
using namespace std;
#define int long long
const int L=5e5+10;
int n,m,a[L],ans[L],rs[L],last[L];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		
		if(!last[a[i]]){
			last[a[i]]=i;
		}
		else{
			rs[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			if(rs[a[j]]){
				
				ans[a[j]]++;
				j=rs[a[j]]+1;				
			}
			else{
				ans[a[j]]++;
				j++;
			}
		} 		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
