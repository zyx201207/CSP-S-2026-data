#include<bits/stdc++.h>//锁贪心 //贪心没想出来，预计75 
using namespace std;
typedef long long ll;
const int N=5e5+10;//nlogn or n
int n;
ll m,num[N],as[N],ans=0;//原数组和差分数组 
bool flag=1,ffg=1;

ll qiuhe(int a,int b,int c){return ((a+b)*c)>>1;}

bool cmp(ll x,ll y){
	return x<y;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>num[i];
		if(num[i]-num[i-1]!=1) flag=0;
		as[i]=as[i-1]+num[i];
		
	}
	for(int i=3;i<=n;++i) if(num[i]-num[i-1]!=num[2]-num[1]) ffg=0;
	
	sort(num+1,num+n+1,cmp);//保证二分合法 
	
	if(flag){//a[i]==i的情况 //15
		while(qiuhe(1,ans,ans)<=m) ans++;
		if(ans>n) ans=n;
		cout<<ans;
		return 0;
	}
	else if(ffg){//等差数列情况 //10
		ll cnt=0;
		ll i=n;
		while(cnt<=m){
			cnt+=num[n]-num[--i];
			ans++;
		}
		if(ans>n) ans=n;
		cout<<ans;
		return 0;
	}
	else if(n<=5010){//50
		for(int i=1;i<=n;++i){
			ll cnt=0,las=m;
			for(int j=i-1;j>0;--j){
				if(num[i]-num[j]<=las){
					cnt++;
					las-=num[i]-num[j];
				}
			}
			cnt++;//加上自己 
			ans=max(ans,cnt);
		}
			
		cout<<ans;
		return 0;
	}
	else {//二分优化 //25
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			int hhe=as[i]-as[mid-1];
			int nnum=i-mid+1;
			if(nnum*num[i]-hhe<=m) r=mid;
			else l=mid+1; 
		}
		ans=max(ans,(ll)(i-l+1));
		}
		cout<<ans;
		return 0;
	}
	return 0;
}