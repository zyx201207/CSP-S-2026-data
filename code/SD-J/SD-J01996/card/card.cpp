#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
bool op=1,op2=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==a[i-1])op=0;
		if(a[i]<a[i-1])op2=0;
	}
	if(op2==1||op==1){
		bool s[200001]={0};
		for(int j=1;j<=m;j++){
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int k=i;k<=n;k++){
					if(a[k]==j){
						ans++;
						break;
					}
				}
			}
			cout<<ans<<" ";
		}
	}
	return 0;
}
