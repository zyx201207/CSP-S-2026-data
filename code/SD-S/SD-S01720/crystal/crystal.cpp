#include<bits/stdc++.h>
using namespace std;
int n,tsA=1,cnt[1000000],tsB=1,jg;
long long m,a[1000000],sum;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			tsA=0;
		}
	}
	if(a[3]-a[2]==a[2]-a[1]){
		jg=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=jg){
				tsB=0;
			}
		}
	}else{
		tsB=0;
	}
	if(tsA==1){
		long long sumA=m;
		int cntA=1;
		for(long long i=1;i<=m;i++){
			sumA-=i;
			cntA++;
			if(sumA<0 || cntA>n){
				cout<<cntA-1;
				return 0;
			}
			else if(sumA==0 || cntA==n){
				cout<<cntA;
				return 0;
			}
			
		}
	}
	if(tsB==1){
		long long sumB=m;
		int cntB=1;
		for(long long i=1;i<=m;i++){
			sumB=sumB-(i*jg);
			cntB++;
			if(sumB<0 || cntB>n){
				cout<<cntB-1;
				return 0;
			}
			else if(sumB==0 || cntB==n){
				cout<<cntB;
				return 0;
			}
			
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int js=1;
		long long zh=m;
		for(int j=i+1;j<=n;j++){
			long long cha=a[i]-a[j];
			zh-=cha;
			js++;
			if(js>n-i+1 || zh<0){
				cnt[i]=js-1;
				break;
			}
			else if(js==n-i+1 || zh==0){
				cnt[i]=js;
				break;
			}
		}
	}
	sort(cnt+1,cnt+n+1,cmp);
	cout<<cnt[1];
	return 0;
} 
