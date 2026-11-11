#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+8;
typedef long long ll;
int n;
ll m,a[MAXN],tmp[MAXN];
bool flag=true;
inline ll read(){
	ll x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch))f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=2;i<=n;i++)tmp[i]=a[i]-a[i-1];
	for(int i=3;i<=n;i++)
		if(tmp[i]!=tmp[i-1]){
			flag=false;
			break;
		}
	sort(a+1,a+n+1);
	if(flag){
		for(int i=n-1;i>=1;i--){
			m-=(a[n]-a[i]);
			if(m<0)return cout<<n-i,0;
		}
	}
	ll mx=0;
	for(int i=n;i>=1;i--){
		if(a[i]==a[i+1])continue;
		ll s=0;
		for(int j=i-1;j>=1;j--){
			s+=a[i]-a[j];
			if(s==m){
				mx=max(mx,(ll)i-j+1);
				break;
			}else if(s>m){
				mx=max(mx,(ll)i-j);
				break;
			}
		}
	}
	cout<<mx;
	return 0;
} 
