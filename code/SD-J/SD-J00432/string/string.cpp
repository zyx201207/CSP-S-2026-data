#include<bits/stdc++.h>
using namespace std;
long long num[200005];
char zm[200005];
long long ans,tmp;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){ 
		scanf("%lld",&num[i]);
		cin>>zm[i];
	}
int lef=1,righ=n;
	while(lef<righ){
		tmp=min(num[lef],num[righ]);
		if(zm[lef]!=zm[righ]){
			ans+=tmp;	
		}
		if(num[lef]==tmp){
			lef++;
			num[righ]-=tmp;
		}
		if(num[righ]==tmp){
			righ--;
			num[lef]-=tmp;
		}
	}
	printf("%lld",ans);
	return 0;
}
