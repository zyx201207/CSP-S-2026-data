#include<bits/stdc++.h>
//Trick||Treat!
#define int long long
const int N=1e6+10;
using namespace std;
int n,a[N],cnt;
char b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]<0&&l+1!=r){
			a[l+1]-=(0-a[l]);
			a[l]=0;
		}
		if(a[r]<0&&r-1!=l){
			a[r-1]-=(0-a[r-1]);
			a[l]=0;
		}
		
		if(a[l]==a[r]){
			if(b[l]!=b[r]){
				cnt+=a[l];
			}
		}else if(a[l]>a[r]){
			int d=a[l]-a[r];
			cnt+=a[r];
			if(l==r-2){
				cnt+=(a[l]+a[r]-1)/2;
				break;
			}
			else if(b[l]!=b[r-1]){
				cnt+=d;
				a[r-1]-=d;
			}else{
				a[r-1]-=d;
			}
		}else if(a[l]<a[r]){
			int d=a[r]-a[l];
			cnt+=a[l];
			if(r==l+2){
				cnt+=(a[r]+a[l]-1)/2;
				break;
			}
			if(b[l+1]!=b[r]){
				cnt+=d;
				a[l+1]-=d;
			}else{
				a[l+1]-=d;
			}
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
