#include<bits/stdc++.h>
using namespace std;
int n,m,a[500008],x=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++){
		if(a[i]>a[i+1])
			x=0;
	}
	if(x==1){
		for(int i=1;i<=m;i++){
			cout<<n<<' ';
		}
		return 0;
	}
	cout<<n<<' '; 
	for(int i=2;i<=m;i++)
		cout<<m<<' ';
	return 0;
} 
