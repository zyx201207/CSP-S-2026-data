#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			if(a[l]==a[r]){
				l++;
				r--;
			}
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
		}
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			if(a[l]==a[r]){
				ans+=a[r];
				l++;
				r--;
			}
			if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
