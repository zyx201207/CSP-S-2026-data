#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int f[3005];
int flag=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		for(int j=i-1;j<=n;j++){
			f[a[j]]++;
		}
		if(f[i]%2==1){
			cout<<i<<' ';
			flag=1;
		}
	}
	if(flag==0){
		for(int i=1;i<=n;i++){
			cout<<i<<' ';
		}
	}
	return 0;
}
