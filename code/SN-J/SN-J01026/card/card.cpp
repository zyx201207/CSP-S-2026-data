#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000];
long long b[1000000];
void abc(int x){
	long long c[n];
	c[x]=a[x];
	long long k=x=1;
	for(int i=x+1;i<=n;i++){
		for(int j=x;j<=i-1;j++){
			if(a[j]==a[i]){
			k=j;
			break;	
			}
		}
		c[k]==a[i];
		k++;
	}
	for(int i=x;i<=n;i++){
		b[a[i]]++;
	}
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(n--){
		abc(n);
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
