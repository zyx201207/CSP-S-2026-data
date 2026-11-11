#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100100],bj[10010][10010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
} 
