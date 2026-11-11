#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans[500005],pian[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>1000){
		for(int i=1;i<=n;i++){
			pian[a[i]]+=i;
		}
		for(int i=1;i<=m;i++){
			cout<<pian[i]<<' ';
		}
		return 0;
	} 
	for(int i=1;i<=n;i++){
		vector<long long> v;
		for(int k=i;k<=n;k++){
			if(k==1){
				v.push_back(a[k]);
				continue;
			}
			bool f=0;
			for(int j=(int)v.size()-1;j>=0;j--){
				if(v[j]==a[k]){
					f=1;
					while(v.back()!=a[k]){
						v.pop_back();
					}
					break;
				}
			}
			if(!f){
				v.push_back(a[k]);
			}
		}
		for(long long x:v){
			ans[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' '; 
	}
	return 0;
}
