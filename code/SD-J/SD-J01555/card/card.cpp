#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[100000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cout<<a[i]<<" ";
	}
	
	return 0;
}

