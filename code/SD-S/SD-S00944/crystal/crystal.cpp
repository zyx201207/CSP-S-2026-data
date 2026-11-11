#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=710005;
long long shuijing[maxn],quesh1[maxn],shuijinghe[maxn],k;
//li daijiaa(int zuo1,int you1){
//	return shuijinghe[you1]-shuijinghe[zuo1-1];
//}//migrate
bool hefafa(int zuo1,int you1){//base --- you1
	if(zuo1>you1)return 0;
	if(zuo1<1)return 0; 
	return ((shuijinghe[you1]-shuijinghe[zuo1-1]-quesh1[you1]*(you1-zuo1+1))<=k);
}//minimax
int hefafff(int you1){
//	printf("%d \n",you1);
	int zuob1an=1,youb1an=you1,shengxiao=you1+1;
	long long mub1ao=quesh1[you1];
	while(zuob1an<youb1an){
		int zhongb1an=((zuob1an+youb1an)>>1);
//		printf("%d %d %d %d\n",you1,zuob1an,zhongb1an,youb1an);
		if(hefafa(zhongb1an,you1)){
			shengxiao=zhongb1an;
			youb1an=zhongb1an;
		}
		else zuob1an=zhongb1an+1;
	}
	return you1-shengxiao+1;
//	if((shuijinghe[you1]-shuijinghe[zuo1-1])<=k)return you1-zuo1+1;return you1-zuo1;
}//mistery
bool jiancha(int zuo1,int you1){
	return 0; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&shuijing[i]);
	sort(shuijing+1,shuijing+n+1);
	long long shujing=shuijing[n];
	for(int i=1;i<=n;i++){
		long long queque1=shujing-shuijing[i];
		quesh1[i]=queque1;
		shuijinghe[i]=shuijinghe[i-1]+queque1;
//		printf("%lld in %d\n",quesh1[i],i);
	}
	quesh1[n+1]=-1;
	int answerw1r=0;
	for(int i=1;i<=n;i++){
		if(quesh1[i]==quesh1[i+1])continue; 
//		long long jizhunzh1=quesh1[i];
		answerw1r=max(answerw1r,hefafff(i));
	}
	printf("%d",answerw1r);
	return 0;
}//Oct31==Dec25...
//(14:31) 1437 time!!!
//don't to rapid to open T2
//100
