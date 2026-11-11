#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	long long minn=0x7fffffffffffffff;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<"\n";
//	}
//	cout<<"\n"<<minn<<"\n";
	long long cnt=0;
	int l=1,r=1,ans=1;
	int ansl=0,ansr=0;
	while(r<=n){
		if(r==n&&l==r){
			break;
		}else if(l>r&&r!=n){
			r++;
		}
		while(r<=n){
			if(a[r+1]==a[r]){
				r++;
			}else{
				if(cnt+(a[r+1]-a[r])*(r-l+1)<=m){
					cnt+=(a[r+1]-a[r])*(r-l+1);
					r++;
				}else{
					break;
				}
			}
		}
//		if((r-l+1)>ans){
//			ansl=l;
//			ansr=r;
////			cout<<l<<" "<<r<<" "<<cnt<<"\n";
//		}
		ans=max(ans,r-l+1);
		cnt-=a[r]-a[l];
		l++;
	}
	cout<<ans;
//	cout<<"\n"<<ansl<<" "<<ansr;
	return 0;
}
