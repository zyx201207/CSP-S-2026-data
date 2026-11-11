#include<bits/stdc++.h>
using namespace std;
long long nge,mge,ans[200005],maxx,andd=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>nge>>mge;
	for(int i=1;i<=nge;i++){
		cin>>ans[i];
		maxx=max(maxx,ans[i]);
		andd&=ans[i];
	}
	if(mge==1){
		cout<<maxx;
		return 0;
	}
	if(mge==nge){
		cout<<andd;
		return 0;
	}
	if(mge==2){
		long long maxxx=0;
		for(int i=1;i<nge;i++){
			for(int j=2;j<=nge;j++){
				if(i!=j){
					maxxx=max(maxxx,ans[i]&ans[j]);
				}
			}
		}
		cout<<maxxx;
		return 0;
	}
	return 0;
}
