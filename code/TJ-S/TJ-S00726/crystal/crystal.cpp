#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=0,flag=1;
	x=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=x){
			flag=0;
		}
	}
	if(flag==1){
		int f=1;
		for(int i=1;i<=n;i++){
			if(a[i]-a[i-1]!=1){
				f=0;
			}
		}
		if(f==1){
			int i=1;
			int ans=1;
			while(i<=m){
				m-=i;
				ans++;
				i++;
			}
			cout<<ans;
		}
		else{
			int i=x;
			int ans=1;
			while(i<=m){
				m-=i;
				ans++;
				i+=x;
			}
			cout<<ans;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long cnt=0;
		long long m1=m;
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]<=m1){
				m1-=a[i]-a[j];
				cnt++;
			}
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}
