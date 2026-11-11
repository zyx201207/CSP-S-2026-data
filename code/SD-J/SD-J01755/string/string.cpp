#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool flag=1;
int n,a[N];
char c[N];
long long sum[N],sum1[N],num,cnt1,cnt2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	sum1[1]=a[1];
	for(int i=2;i<=n;i++){
		sum1[i]=sum1[i-1]+a[i];
	}
	long long las=0;
	for(int i=1;i<=n;i++){
		if(c[i]!=c[i+1]){
			sum[++cnt2]=sum1[i]-sum1[las];
			flag=0;
			cnt1=i;
			las=i;
		} 
	}
	if(flag){
		cout<<0;
		return 0;
	}
	if(cnt2==1){
		cout<<sum[cnt1];
		return 0;
	}
	if(num-sum[cnt2/2+1]>=sum[cnt1]) cout<<num-sum[cnt2/2+1]-1;
	else cout<<sum[cnt1];
	return 0;
}
