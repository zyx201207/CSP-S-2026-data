#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=2e5+5;
LL a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	LL l=1,r=n;
	LL cnt=0;
	while(l<r){
		if(c[l]==c[r]){
			LL x=min(a[l],a[r]);
			a[l]-=x;
			a[r]-=x;
			if(a[l]==0){
				l++;
			}
			if(a[r]==0){
				r--;
			}
		}else{
			LL x=min(a[l],a[r]);
			a[l]-=x;
			a[r]-=x;
			if(a[l]==0){
				l++;
			}
			if(a[r]==0){
				r--;
			}
			cnt+=x;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
