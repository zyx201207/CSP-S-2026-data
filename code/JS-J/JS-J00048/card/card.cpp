#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>mp(n+1);
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	for(int i=2;i<=n;i++){
		mp[i]=mp[i-1]+mp[i];
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
		}
}
