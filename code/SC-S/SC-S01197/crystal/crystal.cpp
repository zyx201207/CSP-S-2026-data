#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans,b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		int c[i],num=i;
		long long sum=m;
		for(int j=1;j<=i;j++)
			c[j]=a[i]-a[j];
		while(sum-c[num]>=0&&num>0){
			sum=sum-c[num]; 
			num--;
			b[i]++;
		}
		if(b[i]>=i-1)
			break;
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,b[i]);
	cout<<ans; 
	return 0;
}
