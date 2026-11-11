#include<bits/stdc++.h>
using namespace std;
const int N=2*10000+10;
int n,m;
long long a[N];
long long max1,max2,max3;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		max1=max(max1,a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==max1) continue;
		max2=max(max2,a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==max1||a[i]==max2) continue;
		max3=max(max3,a[i]);
    }
	cout<<(max1|max2|max3);
	return 0;
}
