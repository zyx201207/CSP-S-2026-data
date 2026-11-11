#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int r=n;
	for(int l=1;l<=n;){
		//cout<<l<<" "<<r<<" ";
		if(r<=l)break;
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				//cout<<a[l]<<" ";
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				//cout<<a[l]<<" ";
				ans+=a[l];
				r--;
				l++;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				r--;
				l++;
			}
		}
		//cout<<ans<<"\n";
	}
	cout<<ans;
	return 0;
} 
