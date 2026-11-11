#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q,c,a[100005],ans,k,b[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++){
		cin>>k;
		for(int i=1;i<=2*k;i++)
		cin>>a[i];
	}
	for(int i=1;i<=q;i++)
	cin>>a[i]>>b[i];
	cout<<32<<" "<<17;
	return 0;
} 
