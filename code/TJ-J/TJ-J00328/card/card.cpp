#include<bits/stdc++.h> 
using namespace std;
int n,m,v[999999]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		for(int k=1;k<=i;k++){
			if(v[k]==v[i]){
				cout<<v[k-i];
			}
		}
	}
	return 0;
}
