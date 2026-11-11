#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
ll m,n;
ll a[N],aa[N];
ll cnt[N];
void aaa(int ii,int jj){
	for(int i=ii;i<=jj;i++)
		a[i]=0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		aa[i]=a[i];
	}
	for(int f=1;f<=n;f++){
		for(int i=f;i<=n;i++){
			for(int j=n;j>f;j--)
				if(a[j]==a[i]){
					aaa(i,j-1);
					break;
				}
		}
		for(int i=f;i<=n;i++)
			if(a[i]!=0)
				cnt[a[i]]++;
		for(int i=f;i<=n;i++)
			a[i]=aa[i];
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",cnt[i]);
	return 0;
}
