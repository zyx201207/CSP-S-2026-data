#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000000],b[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a;
	}
	return 0;
}
