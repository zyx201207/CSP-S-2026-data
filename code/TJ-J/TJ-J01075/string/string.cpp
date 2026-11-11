#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	string a[100000];
	int n,l,k=0,ans=0;
	string z;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>z;
		for(int j=1;j<=l;j++){
			a[k+j]=z;
			
		}k+=l;
	}
	int y=k/2;
	for(int i=1;i<=y;i++){
		if(a[i]!=a[k-i+1]){
			ans++;
		}
	}cout<<ans;
}
