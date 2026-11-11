#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,M=1e3+10;
int n,m,ma=INT_MIN,mai;
struct node{
	int id;
	int w;
	bool b[36];
	int cn;
}a[N];
node stm;
bool cmp(node x,node y){
	/*if(x.id==mai){
		return 1;
	}
	if(y.id==mai){
		return 0;
	}*/
	int mac=max(x.cn,y.cn);
	int sum1=0;//,summ1=0;
	for(int i=1;i<=mac;i++){
		//sum1+=((x.b[i]==a[mai].b[i])&&a[mai].b[i]==1);
		if(x.b[i]==1&&stm.b[i]==1){
			sum1++;
		}
		//cerr<<x.b[i]<<" ";
		//summ1+=(x.b[i]==a[mai].b[i])*(1<<(i-1));
	}
	//cerr<<"\n";
	int sum2=0;//,summ2=0;
	for(int i=1;i<=mac;i++){
		//sum2+=((y.b[i]==a[mai].b[i])&&a[mai].b[i]==1);
		if(y.b[i]==1&&stm.b[i]==1){
			sum2++;
		}
		//cerr<<y.b[i]<<" ";
		//summ2+=(y.b[i]==a[mai].b[i])*(1<<(i-1));
	}
	//cerr<<"\n";
	if(sum1==sum2){
		return x.w>y.w;
	}
	//cerr<<x.w<<" "<<y.w<<"\n";
	//cerr<<sum1<<" "<<sum2<<"\n";
	//cerr<<mai<<"\n";
	return sum1>sum2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].w);
		a[i].id=i;
		int tx=a[i].w;
		int cnt=0,ans=0;
		for(int j=1;j<=33;j++){
			a[i].b[j]=0;
		}
		while(tx){
			a[i].b[++cnt]=(tx&1);
			ans+=a[i].b[cnt];
			tx>>=1;
		}
		a[i].cn=cnt;
		if(ans>ma){
			ma=max(ma,ans);
			mai=i;
		}
	}
	stm=a[mai];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		printf("%d ",a[i].w);
	}
	printf("\n");
	ll sum=a[1].w;
	for(int i=2;i<=m;i++){
		sum=sum&a[i].w;
	}
	printf("%d",sum);
	//cerr<<sizeof(a);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
