#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=5e5+10;
int a[N],n,m,b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.in","w",stdout);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	int p=1,cnt=0;
	for(int i=1; i<=n; i++){
		b[a[i]]++;
	}
	for(int i=1; i<=m; i++){
		printf("%d ",b[i]);
	}
	return 0;
	
} 
