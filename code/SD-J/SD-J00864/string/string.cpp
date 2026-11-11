#include<bits/stdc++.h>
using namespace std;
const int N=200000+5;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r]){
				l++;
				r--;
			}
			else{
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
			else if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}
			else{
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
