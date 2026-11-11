#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[6000],b[6000],ans,s,sum=0;
vector<long long>v[500];
void dfs(long long l,long long r,long long k,long long w){
//	if(l==1&&r==3)cout<<w<<" ";
	if(w>ans)return;
	if(k==r){
		if(w==ans)s++;
		return;
	}
	for(int i=1;a[k+i]-a[k]<=d&&k+i<=r;i++)dfs(l,r,k+i,w+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//t=1,n=6,d=2;
cin>>c>>t;
while(t--){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long l,r;
	for(l=1,r=2;r<=n;){
		if(a[r]-a[l]>d){
			b[l]=r-1;
			l++;
		}
		else{
			r++;
		}
	}
	for(;l<=r;l++)
		b[l]=r-1;
//	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			ans=0,s=0;
			for(int k=i;k<j;){
				if(k==b[k])break;
				ans++;
				k=b[k];
			}
//			cout<<ans<<" ";
			dfs(i,j,i,0);
			if(s==2)sum++;
//			cout<<i<<" "<<j<<" "<<s<<endl;
		}
	}
	cout<<sum<<endl;
}
	return 0;
}
