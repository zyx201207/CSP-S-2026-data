#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=1e5+10;
int n,m,a[N];
map<int,int> mp;
signed main(){ IOS;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0,ans,flag=1,flag2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(i==1) ans=a[i];
		else ans&=a[i];
		if((int)log2(a[i]+1)!=log2(a[i]+1)) flag=0;
		if(a[i]!=i-1) flag2=0;
	}
	if(m==1) return cout<<mx,0;
	if(m==n) return cout<<ans,0;
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		return cout<<ans,0;
	}
	if(n<=20){
		int nn=(int)pow(2,n),ans=0;
		for(int i=1;i<=nn;i++){
			int cnt=0,sum=0,k=1,j=i;
			while(j){
				if(j&1){
					if(k==1) sum=a[k];
					else sum&=a[k];
					cnt++;
				}
				k++;
				j>>=1;
			}
			if(cnt==m) ans=max(ans,sum);
		}
		return cout<<ans,0;
	}
	if(flag){
		sort(a+1,a+1+n);
		int ans;
		for(int i=n;i>=1&&m;i--,m--){
			if(i==n) ans=a[i];
			else ans&=a[i];
		}
		return cout<<ans,0;
	}
	if(flag2){
		int l=0,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			int nn=n;
			while(nn){
				if(nn/2<=mid&&mid<=nn) break;
				nn>>=1;
			}
			if(mid+(m-1)*nn<=n){
				ans=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		return cout<<ans,0;
	}
	int s1=0,s2=0,s3=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) s1++;
		if(a[i]==2) s2++;
		if(a[i]==3) s3++;
	}
	if(s3>=m) return cout<<3,0;
	if(s2>=m) return cout<<2,0;
	if(s1+s3>=m) return cout<<1,0;
	return cout<<0,0;
	return 0;
}
