#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j++){
			if(a[i]==a[j]){
			i=j;
			break;	
			}
		}
	}
	for(int i=1;i<=n;i++){
		
	}
}
