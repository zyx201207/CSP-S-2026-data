#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	vector<int>a(n),tmp;
	for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++){
			if(tmp.empty()){
				tmp.push_back(a[i]);
				continue;
			}
			for(int j=0;j<a.size();j++){
				for(int k=0;k<tmp.size();k++){
				if(a[j]==tmp[k]){
					for(int s=k;s<tmp.size();s++){
					tmp.push_back(a[i])	;
				}
				else tmp.push_back(a[i]);
			}
			for(int j=0;j<tmp.size();j++){
				if(tmp[j]<=m)ans++;
			}
			cout<<ans<<" ";
			ans =0;
			tmp.clear();
		}
return 0;
}

