#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
int cnt,awa[500005],qwq[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	cnt=1;
	awa[cnt]=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			awa[cnt]++;
		}
		else{
			cnt++;
			awa[cnt]++;
			qwq[cnt]=a[i]-a[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+qwq[i];
		
	}
	int tat=1,ans=awa[1],sumn=awa[1],sumt=0;
	for(int i=2;i<=cnt;i++){
		sumt+=sumn*qwq[i];
		while(sumt>m){
			if(sumt-awa[tat]*(s[i]-s[tat])>m){
				sumn-=awa[tat]*(s[i]-s[tat]);
				sumt-=awa[tat];
				tat++;
			}
			else{
				int wtf=(sumt-m-1)/(s[i]-s[tat])+1;
				sumn-=wtf;
				sumt-=wtf*(s[i]-s[tat]);
				awa[tat]-=wtf;
				//if(awa[tat]==0) tat++;
			}
		}
		ans=max(ans,sumn+awa[i]);
		sumn+=awa[i];
	}
	printf("%lld",ans);
	return 0;
}
//wei she me da yang li 4 cuo le
//wei she me da bu liao zhong wen
//byd ping mu hai shi fang de
//shui lai bang wo tiao dai ma(
//ni shuo de dui
//dan jin tian shi xterfusion 1 zhou nian
//he cheng da yin jing
//only feels like nothing could be better when i'm with you
//when i'm with you
