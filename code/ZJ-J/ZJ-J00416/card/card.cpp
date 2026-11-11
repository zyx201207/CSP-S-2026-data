#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int>t;
		for(int j=i;j<=n;j++){
			int f=1;
			for(int k=t.size()-1;k>=0;k--){
				if(t[k]==a[j]){
					f=0;
					break;
				}
			}
			if(f==0){
				for(int k=t.size()-1;k>=0;k--){
					t.erase(t.begin()+k);
					if(t[k]==a[j]){
						break;
					}
				}
			}
			t.push_back(a[j]);
		}
		for(int j=0;j<t.size();j++){
			ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	
	
	return 0;
}
