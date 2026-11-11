#include <bits/stdc++.h>
using namespace std;
int n,m;
int b[300005],c[300005];
int a[500005];

int main (){
    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		c[a[i]]=i;
	} 
	for (int i=1;i<=m;i++){
		if (b[i]%2 == 1){
			cout<<c[i];
			continue;
		}
		else if (b[i]%2==0){
			cout <<0;
			continue;
		}
		cout<<i;
	} 
	return 0;
}

