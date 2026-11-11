#include<bits/stdc++.h>
#define N 2000005
#define M 5005
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int c,t,n,d,a[N],dp[N],num[N];
//vector<int> e[N/10];

void suba(){
	int cha=a[2]-a[1];
//	printf("%lld\n",cha);
	if(cha>=d){
		printf("0\n");
		return;
	}
	int num=d/cha;
//	printf("num:%lld\n",num);
	if(num<=1){
		printf("0\n");
		return;
	}
	int pos=num+num;
	printf("%lld\n",max(n-pos+1,0ll));
}
void subbaoli(){
	int ans=0;
	for(int s=1;s<=n;s++){
		for(int i=1;i<=n;i++){
			dp[i]=INF;
		}
		for(int i=1;i<=n;i++){
			num[i]=0;
		}
		dp[s]=0;
		num[s]=1;
		for(int i=s+1;i<=n;i++){
			for(int j=i-1;j>=s;j--){
				if(a[i]-a[j]<=d){
					if(dp[i]==dp[j]+1) num[i]+=num[j];
					else if(dp[i]>dp[j]+1){
						dp[i]=dp[j]+1;
						num[i]=num[j];
					}
				}
				else break;
			}
		}
		for(int i=s+1;i<=n;i++){
			ans+=(num[i]==2);
		}
	}
	printf("%lld\n",ans);
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate1.in","r",stdin);
//	freopen("migrate1_my.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
//		printf("tiaoshi:%lld\n",t);
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n==1){
			printf("0\n");
			continue;
		}
		if(c==11||c==12){
			suba();
			continue;
		}
		if(c==13||c==14){
			printf("0\n");
			continue;
		}
		subbaoli();
//		for(int i=1;i<=n;i++){
//			for(int j=i-1;j>=1;j--){
//				
//			}
//		}
	}
	return 0;
}//知颖你太美