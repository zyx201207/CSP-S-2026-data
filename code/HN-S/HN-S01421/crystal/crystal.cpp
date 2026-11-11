#include<bits/stdc++.h>
using namespace std;
long long liang[500005],kuai[500005];
int jin;
long long shu,ban;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&jin,&shu);
	for(int i=1;i<=jin;i++){
		scanf("%lld",&liang[i]);
	}
	sort(liang+1,liang+jin+1);
	liang[0]=kuai[0]=0;
	for(int i=1;i<=jin;i++){
		kuai[i]=liang[i]+kuai[i-1];
	}
	for(int i=1;i<=jin;i++){
		int l=0,r=i;
		while(l<=r){
			long long mid=(l+r)/2;
			if(liang[i]*mid-(kuai[i]-kuai[i-mid])<=shu){
				ban=max(ban,mid);
				l=mid+1;
			}
			else r=mid-1;
		}
	}
	printf("%lld",ban);
	return 0;
}