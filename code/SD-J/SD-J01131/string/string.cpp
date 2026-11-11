#include<bits/stdc++.h>
using namespace std;
long long n,a[210000],ans;
char c[210000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
				if(a[l]<=0){
					l++;
				}
			}else{
				a[r]-=a[l];
				l++;
				if(a[r]<=0){
					r--;
				}
			}
		}else{
			if(a[l]>a[r]){ 
				ans+=a[r];
//				cout<<ans<<" "<<a[r]<<" ans1\n";
				a[l]-=a[r];
				r--;
				if(a[l]<=0){
					l++;
				}
			}else{
				ans+=a[l];
//				cout<<ans<<" "<<a[l]<<" ans2\n";
				a[r]-=a[l];
				l++;
				if(a[r]<=0){
					r--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
