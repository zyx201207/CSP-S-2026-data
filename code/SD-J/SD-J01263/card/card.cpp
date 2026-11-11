#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=2e5+10;
int a[N];
map<int,int> mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		map<int,int> flag,ans;
		for(int j=i;j<=n;j++){
			if(flag[a[j]]){
				ans.clear();
				ans[a[j]]++;
			}
			else{
				flag[a[j]]=1;
				ans[a[j]]++;
			}
		}
//		cout<<i<<" : ";
		for(auto it:ans){
			mp[it.first]+=it.second;
//			cout<<it.first<<" "<<it.second<<"   ";
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<mp[a[i]]<<" ";
	}
	return 0; 
}

/*

4 3
1 2 1 3


10 3
3 1 2 1 3 2 3 1 2 1

*/ 
