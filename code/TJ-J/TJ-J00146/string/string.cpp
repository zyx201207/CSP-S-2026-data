#include<bits/stdc++.h>
using namespace std;
#define int long long
struct unll{
	int f;
	char s;
} a[200005];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].f>>a[i].s;
	}
	int o1=1,o2=n,ans=0;
	while(o2>o1){
		if(a[o1].s==a[o2].s){
			if(a[o1].f>a[o2].f){
				
				a[o1].f-=a[o2].f;o2--;
			}
			else if(a[o1].f<a[o2].f){
				
				a[o2].f-=a[o1].f;o1++;
			}
			else{
				o1++;
				o2--;
			}
		}
		else{
			if(a[o1].f>a[o2].f){
				ans+=a[o2].f;
				a[o1].f-=a[o2].f;o2--;
			}
			else if(a[o1].f<a[o2].f){
				ans+=a[o1].f;
				a[o2].f-=a[o1].f;o1++;
			}
			else{
				ans+=a[o2].f;
				o1++;o2--;
			}
		}
	}
	cout<<ans;
	
	
	return 0;
} 
