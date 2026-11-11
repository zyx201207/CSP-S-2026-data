#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N];
ll ans,cnt,t;
ll flag,v[205];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>100||a[i]<-100)flag=1;
	}
	if(n<=5000){
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			t=m,cnt=0;
			for(int j=i-1;j>=1;j--){
				t-=a[i]-a[j];
				if(t<0){
					break;
				}
				else{
					cnt++;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans+1;
	}
	else if(!flag){
		for(int i=1;i<=n;i++)v[a[i]+100]++;
		for(int i=0;i<=200;i++){
			if(v[i]==0)continue;
			t=m,cnt=v[i];
			for(int j=i-1;j>=0;j--){
				if(t-(i-j)*v[j]>=0){
					t-=(i-j)*v[j];
					cnt+=v[j];
				}
				else{
					cnt+=t/(i-j);
					break;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+1+n);
		for(int i=n-1;i>=0;i--){
			if(m-(a[n]-a[i])>=0){
				ans++;
				m-=a[n]-a[i];
			}
			else{
				cout<<ans+1;
				return 0;
			}
		}
	}
	return 0;
}
