#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100];
	int p=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==2) p++;
	}
	int b[3];
	b[a[n]]=a[n];
	if(a[n]==3)
	cout<<3<<" "<<p<<" "<<n;
	if(a[n]==1)
	cout<<n<<" "<<p<<" "<<3;
	return 0;
}
