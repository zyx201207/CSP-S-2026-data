#include <bits/stdc++.h>
using namespace std;
long long a,b,c[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)cin>>c[i];
	sort(c+1,c+1+a);
	long long k=c[a];
	for(int i=a-1,l=1;l<=b;i--,l++){
		k=k&c[i];
	}cout<<k;return 0;
}
