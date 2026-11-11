#include<bits/stdc++.h>
using namespace std;

long long a[1000000],pre[1000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	/*cout<<"a:\n";
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<"\n";*/
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	/*cout<<"pre:\n";
	for(int i=1;i<=n;i++)cout<<pre[i]<<" ";
	cout<<"\n";*/
	long long ans=1;
	for(int i=1;i<=n;i++){
		//cout<<i<<":\n";
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			//cout<<"l r mid"<<l<<" "<<r<<" "<<mid<<"\n";
			long long cnt=i-mid+1;
			long long pls=a[i]*cnt-(pre[i]-pre[mid-1]);
			//cout<<"pls "<<pls<<"\n";
			if(pls<=m){
				//cout<<"OK ";
				r=mid-1;
				ans=max(ans,cnt);
				//cout<<ans<<"\n";
			}
			else{
				//cout<<"gui\n";
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
