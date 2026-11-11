#include<bits/stdc++.h>

using namespace std;

long long n,a[200005],ans;
char b[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(b[l]==b[r]){
			a[l]-=min(a[l],a[r]);
			a[r]-=min(a[l],a[r]);
			if(a[l]==0){
				l++;
			}
			if(a[r]==0){
				r--;
			}
		}else{
			long long q=min(a[l],a[r]);
			ans+=q;
			a[l]-=q;
			a[r]-=q;
			if(a[l]==0){
				l++;
			}
			if(a[r]==0){
				r--;
			}
		}
	}
	cout<<ans; 
	return 0;
}
