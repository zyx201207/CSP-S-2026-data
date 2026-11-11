#include<bits/stdc++.h>
using namespace std;
long long n,m,c=0;
int a[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=m;i++){
		int x=0;
		for(int j=0;i<n;j++){
			x++;
			if(a[j]==i) c++;		
		}if(i==m) cout<<n;
		else cout<<c<<" ";
		
	}
	
}































