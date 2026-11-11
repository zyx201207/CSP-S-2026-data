#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],pow2[30];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	pow2[0]=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	int t=n,r=m;
	if(r==1){
		ll ans=0;
		for(int i=1;i<=t;i++)ans=max(ans,a[i]);
		cout<<ans;
	}else if(r==t&&r!=1){
		int ans=INT_MAX;
		for(int i=1;i<=t;i++)ans=ans&a[i];
		cout<<ans;
	}else if(r==2&&r!=t){
		ll ans=0;
		for(int i=1;i<=t;i++)
		    for(int j=1;j<=t&&j!=i;j++)
		        ans=max(ans,a[i]&a[j]);
	    cout<<ans;
	}else if(r==t-1&&r!=1&&r!=2){
		int p=INT_MAX,q=INT_MAX;
		for(int i=1;i<t;i++)p=p&a[i];
		for(int i=2;i<=t;i++)q=q&a[i];
		cout<<max(p,q);
	}else{
	    int flag1=1;
		for(int i=1;i<=t;i++){
			if(a[i]>=4)flag1=0;
		}
		if(!flag1){
			sort(a+1,a+t+1);
			cout<<a[t-r+1];
		}else{
			int d[4]={0,0,0,0};
			for(int i=1;i<=t;i++)d[a[i]]++;
			if(d[3]>=r)cout<<3;
			else{
				r-=d[3];
				if(d[2]>=r)cout<<2;
				else if(d[1]>=r)cout<<1;
				else cout<<0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}