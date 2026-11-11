#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int n,a[200005];
long long ans; 
char c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[r]>a[l]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
			else if(a[r]<a[l]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			else {
				ans+=a[l];
				l++,r--;
			}
		}
		else {
			if(a[r]>a[l]){
				a[r]-=a[l];
				l++;
			}
			else if(a[r]<a[l]){
				a[l]-=a[r];
				r--;
			}
			else {
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
