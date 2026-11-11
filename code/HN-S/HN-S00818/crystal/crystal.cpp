#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,m,tot;
int a[N],s[N];
pair<int,int> b[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	a[0]=-1e18;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			b[++tot]={a[i],1};
			while(i<=n&&a[i+1]==a[i])
				b[tot].second++,i++;
		}
	}
	if(tot==1){
		cout<<n;
		return 0;
	} 
	int ans=-1e18,len=b[1].second;
	for(int i=2;i<=tot;i++){
		int lt=0,rt=len+1;
		while(lt+1<rt){
			int mid=(lt+rt)>>1;
			if(b[i].first*(len-mid+1)-(s[len]-s[mid-1])<=m)
				rt=mid;
			else
				lt=mid;
		}
		ans=max(ans,len-rt+1+b[i].second);
		len+=b[i].second;
	}
	cout<<ans;
	return 0;
}
