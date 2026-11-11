#include<bits/stdc++.h>
using namespace std;
long long n,m,o[10000],q[10000],z,w,ans[10000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>o[i];
	}
	w=1;
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			if(w==1){
				q[w]=o[j];
				w++;
			}
			else{
				for(int e=w;e>0;e--){
					if(q[e]==o[j]){
						w=e;
						break;
					}
				}
				q[w]=o[j];
				w++;
			}
		}
		for(int j=1;j<w;j++){
			ans[q[j]]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<" ";
	}
	return 0;
}
