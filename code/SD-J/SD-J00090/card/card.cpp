#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	vector<ll>a,ans;
	cin>>n>>m;
	a.resize(n+1);
	ans.resize(m+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<ll>sta;
	map<int,ll>mp;
	while(!sta.empty()) sta.pop();
	for(int i=1;i<=n;i++){
		while(!sta.empty()) sta.pop();
		for(int j=1;j<=m;j++){
			mp[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==0){
				sta.push(a[j]);
				mp[a[j]]++;
			}
			else{
				while(!sta.empty() && sta.top()!=a[j]){
					mp[sta.top()]--;
					sta.pop();
				}
				sta.push(a[j]);
				mp[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++){
			if(mp[j]){
				ans[j]++;
			}
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

