#include<bits/stdc++.h>
using namespace std;
int a[500006];
int t[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	
	for(int i=1;i<=n;i++){
		if(i<m){
			cout<<i<<" ";
		}
		else{
			cout<<m<<" ";
		}
		
	}
	return 0;
}
