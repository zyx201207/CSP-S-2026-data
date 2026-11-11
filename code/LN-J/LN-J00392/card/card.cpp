#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[300005];
int zh[300005];
int pz[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int js = 0;
		for(int j = i-1;j<=n;j++){
			if(b[a[j]] == 0){
				b[a[j]] = j;
				js+=1;
				pz[js] = a[j];
			}else{
				while (js>=b[a[j]]){
					pz[js] = 0;
					js-=1;
				}
			}
		}
		for(int i=1;i<=js;i++){
			cout<<pz[i]<<" ";
		}
	}
	for(int i=1;i<=m;i++){
		cout<<zh[i]<<" ";
	}
	return 0;
}
