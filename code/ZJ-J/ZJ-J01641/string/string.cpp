#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+20;
int a[N],n,len,ans=0;
char c[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,lenl=0,lenr=0;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				lenl+=a[l];
				lenr+=a[l];
				l++;
			}else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				lenl+=a[r];
				lenr+=a[r];
				r--;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				lenl+=a[l];
				lenr+=a[l];
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				lenl+=a[r];
				lenr+=a[r];
				r--;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
