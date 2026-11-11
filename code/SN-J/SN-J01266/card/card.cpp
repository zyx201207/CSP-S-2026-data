#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005],b[1000005];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[i]=2;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1])
		b[i]-=2;
		b[i-1]-=2;
	}
	for(int i=1;i<=n;i++){
		cout<<b[i];
	}
	return 0;
} 
