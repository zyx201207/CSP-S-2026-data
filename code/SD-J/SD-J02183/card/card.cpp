#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,a[N],m,ans[M];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]=i;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		if(a[n]==1){
			cout<<n;
			for(int i=n;i>=1;i--){
				if(a[i]==2){
					cout<<" "<<i;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(a[i]==1){
					cout<<i;
				}
			}
			cout<<" "<<n;
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}  
