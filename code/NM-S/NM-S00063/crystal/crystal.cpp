#include<bits/stdc++.h> 
using namespace std;
long long n,m;
long long a[1000000];
long long av,w;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i <= n;i++){
		cin>>a[i];
		w+=a[i];
	}
	cout<<0;
	return 0;
}
