#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1000;
long long n,m,a[N],c[N],cnt=1,sum,ans,f=1;//cnt=1
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	/*ans=1;
	for(int i=2;i<=n;i++){
		cnt=1;
		sum=0;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]+sum<=m){
				sum=a[i]-a[j]+sum;
				cnt++;
			}
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;*/
	for(int i=2;i<=n;i++){
		long long c=a[i]-a[i-1];
		if(sum+c*(i-1-f+1)<=m){
			sum=sum+c*(i-1-f+1);
			cnt++;
			ans=max(ans,cnt);
		}
		else{
			if(c>m){
				cnt=1;
				sum=0;
				continue;
			}
			while(sum+c*(i-1-f+1)>m){
				sum-=a[i-1]-a[f];
				f++;
				cnt--;
			}
			sum=sum+c*(i-1-f+1);
			cnt++;
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
