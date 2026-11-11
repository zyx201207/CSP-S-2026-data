#include <bits/stdc++.h>
using namespace std;
#define int long long
int l,r,ans,n;
struct node{
	int s;
	char c;
}a[201000];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
	}
	r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].s>a[r].s){
				a[l].s-=a[r].s;
				r--;
			}
			else if(a[l].s<a[r].s){
				a[r].s-=a[l].s;
				l++;
			}
			else if(a[l].s==a[r].s){
				l++;
				r--;
			}
		}
		else{
			if(a[l].s>a[r].s){
				ans+=a[r].s;
				a[l].s-=a[r].s;
				r--;
			}
			else if(a[l].s<a[r].s){
				ans+=a[l].s;
				a[r].s-=a[l].s;
				l++;
			}
			else if(a[l].s==a[r].s){
				ans+=a[r].s;
				l++;
				r--;
			}			
		}
	}
	printf("%lld",ans);
	return 0;
}
