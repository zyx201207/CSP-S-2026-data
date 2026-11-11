#include<bits/stdc++.h>
using namespace std;
long long a[1000007],last[1000007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		last[a[i]]=i;
	}
	for(int i=1;i<=m;i++)cout << last[i] << " ";
	return 0;
}
