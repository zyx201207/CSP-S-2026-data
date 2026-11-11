#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int MAXN=2e6+5;
int C,T; 
ll a[MAXN];
ll n,v;
int solve_dc(){
	ll cha=a[2]-a[1];
	if(2*cha>v)return 0;
	ll D=v/cha;
	return max(0*1ll,n-2*D+1);
}
int d[MAXN];
int pat[MAXN];
ll ans;
ll solve_zc(){
	ans=0;
	for(int i=1;i<=n;i++){
		int idx=upper_bound(a+1,a+n+1,a[i]+v)-a;
		if(idx==-1)idx=n+1;
		d[i]=idx-1;
	}
	for(int i=1;i<=n;i++){
		if(i==d[i])continue ;
		for(int s=1;s<=n;s++)pat[s]=0;
		for(int s=i+1;s<=d[i];s++)pat[s]=1;
		int j=d[i];
		while(j<n){
			if(j==d[j])break ;
			int k=d[j];
			for(int l=j+1;l<=k;l++){
				pat[l]=pat[j];
				if(a[l]-a[j-1]<=v)pat[l]+=pat[j-1];
				if(a[l]-a[j-2]<=v)pat[l]+=pat[j-2];
				if(pat[l]>2)pat[l]=3;
				else if(pat[l]==2){
					ans++;
					//printf("+:%d %d\n",i,l);
				}
				else ;
			}
			j=k;
		}
	//	printf("%d\n",i);
	//	for(int j=i+1;j<=n;j++)printf("%d ",pat[j]);
	//	printf("\n");
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>C>>T;
	while(T--){
		memset(a,0x3f,sizeof(a));
		cin>>n>>v;
		for(int i=1;i<=n;i++)scanf("%lld",a+i);
		bool cha_flag=1;
		for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=a[i-1]-a[i-2])cha_flag=0;
		if(cha_flag){
			cout<<solve_dc()<<endl;
			continue ;
		}
		cout<<solve_zc()<<endl;
	}
	return 0;
}
