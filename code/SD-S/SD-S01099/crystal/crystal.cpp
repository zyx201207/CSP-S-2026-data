#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ch[N];
int ans=0;
int check(int p){
	int sum=0;
	int num=0;
	int now=a[p];
	for(int i=p;i>=1;i--){
		sum+=a[p]-a[i];
		if(sum>m){
			break;
		}
		num++;
	}
	if(num>=ans){
		ans=num;
		return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag=1;
	int last=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	last=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=last){
			flag=0;
		}
	}
	for(int i=1;i<=n;i++){
		ch[i]=a[i]-a[i-1];
	}
	if(flag==1){
		int l=1,r=n;
		int mid;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid)==1){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		for(int i=mid;i<n;i++){
			if(a[i]==a[i+1]){
				ans++;
			}
			else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int now=a[i];
		int sum=0;
		int num=0;
		for(int j=i;j>=1;j--){
			sum+=(now-a[j]);
			if(sum>m){
				break;
			}
			num++;
		}
		if(num>=ans){
			ans=num;
		}
	}
	cout<<ans;
	return 0;
}
