#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

struct p{
	bool r;
	ll w;
}s[300005];

ll n,m,a[500005],len,b[500005],s2[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		scanf("%ld",&a[i]);
	}
	for(int k=n;k>=2;k--){
		len=0;
		for(int i=1;i<=k;i++){
			if(!s[a[i]].r){
				b[++len]=a[i];
				s[a[i]].r=1;
				s[a[i]].w=len;
			}
			else{
				len=s[a[i]].w;
				memset(s,0,sizeof s);
				for(int j=1;j<=len;j++){
					s[b[j]].r=1;
					s[b[j]].w=j;
				}
			}
		}
		for(int i=1;i<=len;i++){
			s2[b[i]]++;
		}
	}
	s2[a[1]]++;
	for(int i=1;i<=m;i++){
		printf("%ld ",s2[i]);
	}
	return 0;
}
