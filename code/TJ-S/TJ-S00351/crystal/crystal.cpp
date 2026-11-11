#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,ans,cnt,flag=1;
ll m,a[N],b[N],pre[N],s,res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	res=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=res){
			flag=0;
			break;
		}
	}
	if(n<=5000){ 
		for(int i=1;i<=n;i++){
			res=0,cnt=1;
			for(int j=i-1;j>=1;j--){
				res+=a[i]-a[j];
				if(res>m)break;
				cnt++;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}else if(flag){
		for(int i=1;i<n;i++)pre[i]=pre[i-1]+i*res;
		ans=upper_bound(pre+1,pre+n+1,m)-pre;
		cout<<min(ans,n);
	}else cout<<n;
	return 0;
}
