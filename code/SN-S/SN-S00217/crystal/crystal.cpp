#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m>1e8){
		long long cha=a[2]-a[1];
		long long mx=0;
		for(long long i=1;;i++){
			mx=i;
			if(((cha+i*(cha))*i)/2>m){
				break;
			}
		}
		cout<<mx;
		return 0;
	}
	sort(a+1,a+n+1);
	long long mx=0;
	for(long long i=1;i<=n;i++){
		int cnt=1,s=m;
		for(long long j=i-1;j>=1;j--){
			if(a[i]-a[j]<=s){
				cnt++;
				s-=(a[i]-a[j]);
//				cout<<"i:"<<i<<"\nj:"<<j<<"\ncnt:"<<cnt<<"\n";
			}else{
//				cout<<"break j:"<<j<<"\n";
				break;
			}
		}
		if(cnt>mx){
			mx=cnt;
		}
	}
	printf("%d",mx);
	return 0;
}
