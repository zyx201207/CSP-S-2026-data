#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,k,a[N],ans,cnt,res[N],mx;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n<=20){//1-5
		for(int i=0;i<(1<<n);i++){
			cnt=0;
			for(int j=0;j<n;j++){
				if((1<<j)&i){
					res[++cnt]=a[j];
				}
			}
			if(cnt==k){
				int sum=res[1];
				for(int x=2;x<=cnt;x++){
					sum&=res[x];
				}
				ans=max(ans,sum);
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){//6
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(k==n){//7
		ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n<=2000&&k==2){//8-10
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	int f=1;
	for(int i=0;i<n;i++){
		int x=log2(a[i]);
		if((1<<x)!=a[i]){
			f=0;
			break;
		}
	}
	if(f){//A(13)
		sort(a,a+n,cmp);
		cout<<a[k-1];
		return 0;
	}
	sort(a,a+n,cmp);
	ans=a[0];
	for(int i=1;i<k;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

