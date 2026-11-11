#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
bool cmp(int m,int n){
	return m>n;
}
bool flag=true;
signed main(){
	//Oct31==Dec25?
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int x=a[n-1]-a[n];
	for(int i=1;i<n;i++){
		if(a[i]-a[i+1]!=x){
			flag=false;
			break;
		}
	}
	if(!flag){	
		int ans=1,m2=m;
		for(int j=1;j<n;j++){
			int sum=1;
			for(int i=j+1;i<=n;i++){
				int x=a[j]-a[i];
				if(x>m2)break;
				m2-=x;
				sum++;
			}
			ans=max(ans,sum);
			m2=m;
		}
		cout<<ans;
	}
	else{
		int x=a[n-1]-a[n];
		int sum=0,ans=1;
		for(int i=2;i<=n;i++){
			sum+=(i-1)*x;
			if(sum>m)break;
			ans++;
		}
		cout<<ans;
	}
	return 0;
}
