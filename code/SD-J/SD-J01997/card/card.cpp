#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500005],cnt[300005];
vector <int> desk;

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++){
		
		desk.clear();
		
		for(int j=i;j<=n;j++){
			
			int flag=-1;
			
			for(int k=0;k<desk.size();k++){
				if(desk[k]==a[j])flag=k;
			}
			
			if(flag!=-1){
				for(int k=flag;k<desk.size();k++)desk.pop_back();
				
			}else{
				desk.push_back(a[j]);
			}
			
		}
		
		for(int j=0;j<desk.size();j++)cnt[desk[j]]++;
		
	}
	
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
	
}
