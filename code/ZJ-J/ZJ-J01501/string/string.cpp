#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200006];
char c[200006];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		//cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r]<<" "<<c[l]<<" "<<c[r]<<endl;
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
				if(a[r]==0) r--;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
				if(a[r]==0) r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

