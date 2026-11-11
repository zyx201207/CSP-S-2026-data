#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
unordered_set<int>s;
unordered_set<int>tmp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	for(int i=0;i<=n;i++){
		s.clear();
		for(int j=i+1;j<=n;j++){
			if(s.find(a[j])==s.end()){
				s.insert(a[j]);
			}else{
				s.clear();
				s.insert(a[j]);
			}
		}
		for(int k:s){
			ans[k]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<" ";
	}
	return 0;
}
