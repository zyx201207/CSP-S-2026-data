#include <bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long mid=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mid+=a[i];
	}
	long long L=0,R=0,ans=0;
	mid=(mid+1)/2;
	int l=1,r=n;
	while(L<mid&&mid>R){
		if(L+a[l]<R+a[r]){
			if(c[l]!=c[r]){
				ans+=L+a[l]-max(L,R);
			}
			L+=a[l];
			l++;
		}
		else if(L+a[l]>R+a[r]){
			if(c[l]!=c[r]){
				ans+=R+a[r]-max(L,R);
			}
			R+=a[r];
			r--;
		}
		else{
			if(c[l]!=c[r]){
				ans+=L+a[l]-max(L,R);
			}
			L+=a[l];
			R+=a[r];
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}