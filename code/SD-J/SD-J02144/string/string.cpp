#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
	}
	long long l=1,r=n;
	while(n&&l<r){
		if(s[l]==s[r]){
			if(a[l]>a[r]){
				n=n-a[r]*2;
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r]){
				n-=a[l]*2;
				l++,r--;
			}
			else if(a[l]<a[r]){
				n-=a[l]*2;
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]>a[r]){
				ans+=a[r];
				n-=a[r]*2;
				a[l]-=a[r];
				//cout<<l<<r<<endl;
				r--;
			}
			else if(a[l]==a[r]){
				ans+=a[l];
				n-=a[l]*2;
				//cout<<l<<r<<endl;
				l++,r--;
			}
			else if(a[l]<a[r]){
				ans+=a[l];
				n-=a[l]*2;
				a[r]-=a[l];
				//cout<<l<<r<<endl;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
