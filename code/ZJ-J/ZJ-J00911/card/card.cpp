#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
map<long long,long long> mp;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int ab=1;ab<=n;ab++){
		int a2[500005]={0};
		for(int i=ab;i<=n;i++){
			if(a2[i]==0){
				for(int j=i+1;j<=n;j++){
					if(a[i]==a[j]){
						for(int k=i;k<j;k++){
							a2[k]=1;
						}
						break;
					}
				}
			}
		}
		for(int i=ab;i<=n;i++){
			if(a2[i]==0){
				mp[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}
