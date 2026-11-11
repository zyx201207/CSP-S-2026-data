#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N],ch[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int flag=1,q=a[2]-a[1];
	for(int i=1;i<n;i++){
		if(ch[i]!=q){
			flag=0;
			break;
		}
	}if(flag){
		int p=0;
		for(int i=1;i<n;i++){
			p+=q*i;
			if(q>m)break;
			ans=max(ans,i+1);
		}cout<<ans;
		return 0;
	}
	for(int i=n;i>=1;i--){
		int p=0;
		for(int j=i-1;j>=1;j--){
			p+=a[i]-a[j];
			if(p>m)break;
			ans=max(ans,i-j+1);
//			if(i-j+1==4)cout<<i<<' '<<j<<' '<<p<<endl;
		}
	}cout<<ans;
	return 0;
}
