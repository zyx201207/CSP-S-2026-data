#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
int ans[300001],iin[500001]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>iin[i];
	}
	for(int t=1;t<=n;t++){
		a.clear();
		for(int i=t;i<=n;i++){
			bool f=true;
			for(int j=0;j<a.size();j++){
				if(a[j]==iin[i]){
					while(a.size()-1>j){
						a.pop_back();
					}
					f=false;
				}
			}
			if(f){
				a.push_back(iin[i]);
			}
		}
		for(int i=0;i<a.size();i++){
			ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
