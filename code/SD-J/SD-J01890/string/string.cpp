#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
char c[1000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,ans=0;
	while(l<=r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}else if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
