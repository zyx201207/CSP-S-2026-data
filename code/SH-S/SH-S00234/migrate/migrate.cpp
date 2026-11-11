#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
int c,t;cin>>c>>t;
while(t--){
	int n,d;
	cin>>n>>d;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++){
//		a[i]+=1000000000000000000 ;
//	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	int cha[n];
//	for(int i=1;i<n;i++){
//		cha[i]=a[i+1]-a[i];
//	}
//	for(int i=1;i<n;i++){
//		cout<<cha[i]<<" ";
//	}cout<<endl;
	vector<pair<int,int>> ans;
		ans.push_back({0,0});
for(int i=1;i<=n-1;i++){
	for(int j=i+1;j<=n;j++){
		if(a[j]-a[i]<=d&&a[j+1]-a[i]<=d&&a[j+2]-a[i]>d){
		//	cout<<"suofdyg"<<endl;
			for(int k=j+2;k<=n;k++){
				if(a[k]-a[i]>d&&a[k]-a[j]<=d&&a[k]-a[j-1]>d){
				//	cout<<"psioudfhg"<<endl;
					ans.push_back({i,k});
					break;
				}else if(a[k]-a[j]>d){
					break;
				}
			}
		}
		if(a[j+1]-a[i]>d){
			break;
		}
	}
	if(a[i+1]-a[i]>d){
	ans.push_back({i,i+1});
	}
}
	ans.push_back({n+1,n+1});
//	for(int i=0;i<ans.size();i++){
//		cout<<ans[i].first<<" "<<ans[i].second<<endl;
//	}
//		cout<<endl;
	int o = 0;
	for(int i=1;i<ans.size()-1;i++){
		int frt = ans[i].first-ans[i-1].first;
		int bac = ans[i+1].second-ans[i].second;
		if(ans[i].second-ans[i].first>=3){
				o+=frt*bac;
		}
	
	}
	cout<<o<<endl;
}
	return 0;
}
/*
0 1
10 3
1 4 7 9 11 12 13 14 16 19
*/
