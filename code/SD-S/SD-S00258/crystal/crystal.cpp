#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],b[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long sum=0,cnt=m;
		for(int j=i;j>=1;j--){
			int p=a[i]-a[j];
			if(cnt>=p){
				sum++;
				cnt-=p;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}

