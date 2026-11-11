#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+5);
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			flag=1;
		}
	}
	vector<int> ans(m+5);
	if(flag==0){
		vector<int> v;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				v.push_back(i-1);
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(v[cnt]==i){
				cout<<i<<" ";
				cnt++;
			}
		}
		cout<<n;
		return 0;
	}
	for(int k=1;k<=n;k++){
		map<int,int> mp;
		int l=k,r=k-1;
		vector<int> b(n+5);
		for(int i=k;i<=n;i++){
			if(mp.count(a[i])){
				r=mp[a[i]];
			}else{
				b[++r]=a[i];
				mp[a[i]]=r;
			}
		}
		for(int i=l;i<=r;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
