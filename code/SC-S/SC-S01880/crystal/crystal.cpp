#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int A=5e5+10;
ll n,m,ans=1,l,r,z,sl,sr;
ll a[A],b[A];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<5000){	
		for(int i=1;i<=n;i++){
			l=i-1;r=i+1;z=0;
			while(z<=m){
				ans=max(ans,r-l-1);
				sl=abs(a[i]-a[l]);
				sr=abs(a[r]-a[i]);
				if(l==0&&r==n+1){
					ans=n;
					cout<<ans;
					return 0;
				}else{
					if(l==0){
						r++;z+=sr;
					}else if(r==n+1){
						l--;z+=sl;
					}else{
						if(sl>sr){
							r++;
							z+=sr;
						}else{
							l--;
							z+=sl;
						}
					}
				}
			}
		}
		cout<<ans;
	}else{
		ll s=a[2]-a[1],ss=0,sz=0;
		while(ss<=m){
			sz++;
			ss+=s*((sz+1)/2);
		}
		ans=sz;
		cout<<ans;
	}
	return 0;
}
