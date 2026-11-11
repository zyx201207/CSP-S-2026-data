#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long c;
struct as{
	int t;
	char q;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].q;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].q==a[r].q ){
			if(a[l].t>a[r].t){
				a[l].t-=a[r].t;
				a[r].t=0;
			}else{
				a[r].t-=a[l].t;
				a[l].t=0;
			}
		}else{
			if(a[l].t>a[r].t){
				a[l].t-=a[r].t;
				c+=a[r].t;
				a[r].t=0;
			}else{
				a[r].t-=a[l].t;
				c+=a[l].t;
				a[l].t=0;
			}
		}
		if(a[l].t==0) l++;
		if(a[r].t==0) r--;
	}
	printf("%lld",c);
	return 0;
}
