#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int fg=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1] && i!=1){
			fg=0;
		}
	}
	if(fg){
		cout<<0;
		return 0;
	} 
	int l=1,r=n;
	while(l<=r){
		if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++;
				r--;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}else{
			if(c[l]==c[r]){
				if(a[l]<a[r]){
					a[r]-=a[l];
					l++;
				}else{
					a[l]-=a[r];
					r--;
				}
			}else{
				if(a[l]<a[r]){
					ans+=a[l];
					a[r]-=a[l];
					l++;
				}else{
					ans+=a[r];
					a[l]-=a[r];
					r--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
