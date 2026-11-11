#include<bits/stdc++.h>
#define inf INT_MIN
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans=inf;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int sum,s,su;
		sum=a[1]&a[2];
		for(int i=3;i<n;i++){
			sum=sum&a[i];
		}
		s=a[2]&a[3];
		for(int i=4;i<=n;i++){
			s=s&a[i];
		}
		sum=max(sum,s);
		ans=a[1]&a[2];
		for(int i=3;i<n-1;i++){
			ans=ans&a[i];
		}
		ans=ans&a[n];
		su=a[1]&a[3];
		for(int i=4;i<=n;i++){
			su=su&a[i];
		}
		ans=max(ans,su);
		ans=max(ans,sum);
		cout<<ans;
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
