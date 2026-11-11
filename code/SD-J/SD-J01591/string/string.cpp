#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+10;
ll n,a[N],ans,L,R,cnt;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	L=1,R=n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	while(L<R){
		if(c[L]==c[R]){
			if(a[L]>a[R]){
				a[L]-=a[R];
				R--;
			}else if(a[L]<a[R]){
				a[R]-=a[L];
				L++;
			}else{
				L++,R--;
			}
		}else{
			if(a[L]>a[R]){
				ans+=a[R];
				a[L]-=a[R];
				R--;
			}else if(a[L]<a[R]){
				ans+=a[L];
				a[R]-=a[L];
				L++;
			}else{
				ans+=a[L];
				L++,R--;
			}
		}
	}
	cout<<ans;
	return 0;
}
