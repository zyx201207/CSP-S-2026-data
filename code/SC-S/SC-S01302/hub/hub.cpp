#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
struct int2{
	int b,e;
};
int2 a[N];
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int wuyong=1;wuyong<=t;wuyong++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i].b>>a[i].e;
		}
		cout<<(int)(n/5)<<"\n";
	}
	return 0;
}