#include<bits/stdc++.h>
using namespace std;
const int N=3*1e5+10;
long long n,m,a[N],s[N],x;
int main(){
 	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=n;i>=1;i--){
			if(a[i]==1){
				x=i;
				cout<<x<<" ";
				break;
			}
		}
		if(x!=n){
			cout<<n;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]==i){
				s[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
} 
