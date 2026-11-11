#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],hahhs[100005],hahhss[100005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		hahhs[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		bool iss[n+1];
		memset(iss,false,sizeof iss);
		for(int j=i;j<=n;j++){
			if(!iss[a[j]]){
				hahhss[a[j]]++;
				iss[a[j]]=true;
			}
			else continue;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<hahhss[i]<<" ";
	}
	return 0;
}
