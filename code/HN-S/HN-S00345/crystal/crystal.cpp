#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n;
long long m;
unsigned long long ans;
long long a[N];
long long ans2;
long long qzh[N];
long long tmax;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long cnt=n;
	while((ans<=m)&&(cnt>=1)){
		--cnt;
		ans+=a[n]-a[cnt]; 
	}
	
	ans-=a[n]-a[cnt];
	cnt++;
	long long rest=m-ans;
	for(int i =n-1;i>=1;i--){
		ans2+=a[n]-a[i];
		qzh[i]=a[n]-a[i];
	}
	int bj;
	tmax=n-cnt+1;
	for(int i = n-1;i>=1;i--){
		bj=a[n]-a[i];
		rest+=(a[i+1]-a[i])*(i+1-cnt);
		while((rest>=qzh[cnt-1]-bj)&&(cnt>1)){
			rest-=qzh[cnt-1]-bj;
			cnt--;
		}
		tmax=max(tmax,i-cnt+1);
		if(cnt==1){
			break;
		}
	}
	cout<<tmax;
	return 0;
}
