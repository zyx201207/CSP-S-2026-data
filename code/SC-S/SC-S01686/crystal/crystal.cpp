#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long sum,sum2;
const int N=500010;
long long cnt,ans1,ans2;
long long a[N],b[N],b2[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i]/n;
		sum2+=a[i]%n;
		sum+=sum2/n;
		sum2%=n;
		
	}
	
	int a1=0,a2=0;
	for(int i=1;i<=n;i++){
		b[i]=abs(a[i]-sum);
		a1+=b[i];
	}
	for(int i=1;i<=n;i++){
		b2[i]=abs(a[i]-sum-1);
		a2+=b2[i];
	}
	ans1=n;
	ans2=n;
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	while(a1>m){
		a1-=b[++cnt];
		ans1--;
	}
	cnt=0;
	sort(b2+1,b2+n+1);
	reverse(b2+1,b2+n+1);
	while(a2>m){
		a2-=b2[++cnt];
		ans2--;
		
	}
	//cout<<ans1<<" "<<ans2<<" ";
	cout<<max(ans1,ans2);
	return 0;
}