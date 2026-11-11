#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 yellow1
#define ull unsigned long long
#define rank jkflsfasf
#define time fjklsaflsdfj
inline ll rd(){
	ll k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
ll a[200007],n,m,ans;
bool flag[200007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=rd(),m=rd();
	for(ll i=1;i<=n;i++){
		a[i]=rd();
	}
	for(int i=30;i>=0;i--){
		ll sum=0;
		for(int j=1;j<=n;j++){
			if(!flag[j]&&((a[j]>>i)&1)){
				sum++;
			}
		}
		if(sum>=m){
			ans|=(1<<i);
			for(int j=1;j<=n;j++){
				if(!flag[j]&&(!((a[j]>>i)&1))){
					flag[j]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

