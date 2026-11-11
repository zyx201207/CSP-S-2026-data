#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],sum;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int s=0;
	if(n%2==0){
		
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
			}else{
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
		}else if(a[l]<a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
			}else{
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
		}else if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++;
				r--;
			}else{
				sum+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}

