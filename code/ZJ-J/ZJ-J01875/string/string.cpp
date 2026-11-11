#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;
ll ans=0;
ll num[N];
char c[N];
int main(){
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&num[i],&c[i]);
	}
	int i=1,j=n;
	while(j>i){
		if(c[i]==c[j]){
			if(num[i]==num[j]){
				i++;j--;
			}else{
				if(num[i]>num[j]){
					num[i]-=num[j--];
				}else{
					num[j]-=num[i++];
				}
			}
		}else{
			if(num[i]==num[j]){
				ans+=num[i];
				i++;j--;
			}else{
				if(num[i]>num[j]){
					ans+=num[j];
					num[i]-=num[j--];
				}else{
					ans+=num[i];
					num[j]-=num[i++];
				}
			}			
		}
	}printf("%lld",ans);
	return 0;
}
