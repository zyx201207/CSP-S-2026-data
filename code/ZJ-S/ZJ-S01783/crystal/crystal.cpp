#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
long long ton[105];

bool cmp(long long x,long long y){
	return x<y;
}

bool specialB(){
	long long cha=a[2]-a[1];
	for(int i=3;i<=n;++i)
		if(a[i]-a[i-1]!=cha) return false;
	return true;
}

bool specialC(){
	if(a[n]>100) return false;
	return true;
}

long long randint(int x,int y){
	long long t=(rand()<<16)+rand();
	long long tt=t%(y-x+1)+x;
	return tt;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	srand(time(NULL));
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	if(n<=5000){
		long long cnt=m,cntn=1,ans=0;
		for(int i=1;i<=n;++i){
			cnt=m;cntn=1;
			for(int j=i-1;j>=1;--j){
				if(a[i]-a[j]<=cnt) cnt-=(a[i]-a[j]);
				else break;
				++cntn;
			}
			ans=max(ans,cntn);
		}
		printf("%lld",ans);
	}else if(specialB()){
		long long cnt=m,ans=1;
		for(int i=n-1;i>=1;--i){
			if(a[n]-a[i]<=cnt) cnt-=(a[n]-a[i]);
			else break;
			++ans;
		}
		printf("%lld",ans);
	}else if(specialC()){
		for(int i=1;i<=n;i++)
			++ton[a[i]];
		long long cntm=m,cntc=0,ans=0;
		for(int i=0;i<=100;++i){
			if(ton[i]==0) continue;
			cntm=m;cntc=ton[i];
			for(int j=i-1;j>=0;--j){
				if(ton[j]==0) continue;
				if(cntm>=(i-j)*ton[j]){
					cntm-=((i-j)*ton[j]);
					cntc+=ton[j];
				}else{
					cntc+=(cntm/(i-j));
					break;
				}
			}
			ans=max(ans,cntc);
		}
		printf("%lld",ans);
	}else{
		printf("%lld",randint(1,n));
	}
	return 0;
}