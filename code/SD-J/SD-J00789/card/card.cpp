#include<bits/stdc++.h>
using namespace std;
int n,m,p[500005],o=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		if(o<=m){
			o++;
		}
		cout<<o<<" ";
	}
	return 0;
} 
