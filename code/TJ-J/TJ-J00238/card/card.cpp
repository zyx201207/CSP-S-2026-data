#include<bits/stdc++.h>

using namespace std;
#define int long long
int n,m,a[2000005],f[3000005],T1=1;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1])T1=0;
	}
	if(T1){
		for(int k=1;k<=n;k++){
			vector<int> v;
			for(int i=k;i<=n;i++){
				int f1=0;
				if(a[i]==v[v.size()-1])f1=1;
				if(f1){
					//cout<<i<<endl;
					for(int j=v.size()-1;j>=0;j--){
						if(v[j]==a[i]){
							break;
						}
						v.pop_back();
					}
				}else{
					v.push_back(a[i]);
				}
				
			}
			for(int j=0;j<v.size();j++){
				f[v[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<f[i]<<' ';
		}
	}
	else{
		for(int k=1;k<=n;k++){
			vector<int> v;
			for(int i=k;i<=n;i++){
				int f1=0;
				for(int j=0;j<v.size();j++){
					if(v[j]==a[i]){
						f1=1;
						break;
					}
				}
				if(f1){
					//cout<<i<<endl;
					for(int j=v.size()-1;j>=0;j--){
						if(v[j]==a[i]){
							break;
						}
						v.pop_back();
					}
				}else{
					v.push_back(a[i]);
				}
				
			}
			for(int j=0;j<v.size();j++){
				f[v[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<f[i]<<' ';
		}
	}
	return 0;
}
