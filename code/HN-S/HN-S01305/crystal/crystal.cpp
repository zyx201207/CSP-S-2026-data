#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,sum=0,ans=0,tot=0,l=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		sum+=a[i];
	} 
	sort(a+1,a+1+n);
	sum=1;ans=1;
	for(int i=2;i<=n;i++){
		tot+=sum*(a[i]-a[i-1]);
//		cout<<tot<<" ";
		sum++;
		if(tot<=m){
			ans=max(ans,sum);
		}
		else{
			while(tot>m){
				tot-=a[i]-a[l];
				l++;
				sum--;
			}
			ans=max(ans,sum);
		}
//		cout<<sum<<"\n";
	}
	cout<<ans;
	return 0;
} 
