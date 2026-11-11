#include<bits/stdc++.h>
using namespace std;
long long a[10001],c[10001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,t=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=t;j<=i-1;j++){
			if(a[j]==a[i]){
				t=i;
			}
		}
		for(int j=t;j<=i;j++){
			c[a[j]]++;
		}
	}
	for(int i=1;i<=m;i+=1){
		cout<<c[i]<<" ";
	}
	return 0;
}