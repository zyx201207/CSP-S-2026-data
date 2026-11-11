//SN-S00496
//吴皓轩
//西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,cnt,ans;
long long mc=INT_MAX;
long long a[500010];        
bool cmp(int a,int b){
	return a>b;
}
bool check(int mid)
{
	cnt=0,ans=0;
	for(unsigned long long j=1;j<=n;j++){
		if(mid>=a[j]){
			cnt+=mid-a[j];
			ans++;
		}
	}
	if(cnt>m)return false;
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",atdout);
	cin>>n>>m;
	for(unsigned long long i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	long long l=a[1],r=a[n],mid;
	while(l<=r){
		cnt=0,ans=0;
		mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
