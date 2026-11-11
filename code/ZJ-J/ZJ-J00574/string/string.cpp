#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
signed main(){
	freopen("string6.in","r",stdin);
	freopen("string6.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int mid=len>>1;
	int res=0;
	int mid_id;
	for(int i=1;i<=n;i++){
		res+=a[i];
		if(res>=mid){
			mid_id=i;
			break;
		}
	}
	int ans=0;
	int ll=0;
	int r=n,rr=0;
	for(int l=1;l<=mid_id;l++){
		if(l==mid_id){
			a[l]-=(mid-ll);
			ll=mid;
		}
		else{
			ll+=a[l];
		}
		for(int i=r;i>=l;i--){
			if(l!=mid_id&&i==l){
				break;
			}
			int x=rr;
			rr+=a[i];
			if(rr>ll){
				if(c[i]!=c[l]){
					ans+=(ll-x);
				}
				a[i]-=(ll-x);
				r=i;
				rr=ll;
				break;
			}
			else{
				if(c[i]!=c[l]){
					ans+=a[i];
				}
				if(ll==rr){
					r=i-1;
					break;
				}
			}
		}	
	}
	cout<<ans;
	return 0;
}
