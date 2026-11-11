#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,mid,a[200005],cnt;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				cnt+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		else if(a[l]<a[r]){
			if(c[l]==c[r]){ 
				a[r]-=a[l];
				l++;
			}
			else{
				cnt+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(c[l]==c[r]){
				l++;
				r--;
			}
			else{
				cnt+=a[l];
				l++;
				r--;
			}
		}
	} 
	cout<<cnt;
	return 0;
} 
