#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n;
ll d,a[2000005],s[2000005],b[2000005],mn=1e9,ans,q[2000005],o;
void dfs(int i,ll cnt,int r){
	if(i==r && cnt>2){
		mn=min(cnt,mn);
		if(cnt>mn){
			q[cnt]++;
		}else{
			q[mn]++;
		}
		return;
	}else if(i==r && cnt==2){
		o++;
	}
	for(int j=r;j>=i+1;j--){
		if((s[j]-s[i])<=d){
			dfs(j,cnt+1,r);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
cin>>c>>t;
while(t>0){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>a[i]>>b[i];
		s[i]==a[i]-a[1];
	}
	for(int i=1;i<=n-3;i++){
		for(int j=i+3;j<=n;j++){
			memset(q,0,sizeof(q));
			mn=1e9;
			dfs(i,1,j);
			if(q[mn]==2){
				ans++;
			}
			
		}
		
	}
	cout<<ans<<endl;
	t--;
}
	return 0;
}

