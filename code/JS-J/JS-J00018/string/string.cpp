#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	vector<int>a(n+1,0);
	vector<char>c(n+1);
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]<=a[r]){
				a[r]-=a[l];
				l++;
				if(a[r]==0)r--;
			}else{
				a[l]-=a[r];
				r--;
			}
		}else{
			if(a[l]<=a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
				if(a[r]==0)r--;
			}else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
