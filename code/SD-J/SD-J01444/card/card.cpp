#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pos[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i; 
	}
	for(int i=1;i<=m;i++){
		cout<<pos[i]<<" ";
	}
	return 0;
}

