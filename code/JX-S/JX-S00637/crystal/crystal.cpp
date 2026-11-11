#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],cf[500005];
int sum,ans,minn=1e8,maxn=0;
bool f=1,f3=1;;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
		cf[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]) f=0;
		if(cf[i]!=cf[i+1]) f3=0;
	}
	if(f){
		cout<<n<<endl;
		return 0;
	}
	if(f3){
		for(int i=n;i>=1;i--){
				if(m>=maxn-a[i]) {
					ans++;
					m-=maxn-a[i];
				}
		}	
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n<1000){	
		for(int i=minn;i<=maxn;i++){
			ans=0;
			int mz=m;
			for(int j=1;j<=n;j++){
				if(a[j]<i&&mz>=i-a[j]){
					ans++;
					mz-=i-a[j];
				}
				else if(a[j]==i) ans++;
			}
			sum=max(ans,sum);
		}
	cout<<sum<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}

