#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
int a[500005];
int a1[500005]; 
int b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[a[i]]++;
	}
	if(n==m){
		for(int i=1;i<=m;i++){
			cout<<n<<' ';
		}
	}
	return 0; 
}

