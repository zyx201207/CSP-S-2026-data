#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,l1=0,r1=0;
	while(l<=r){
		if(a[l]-l1>a[r]-r1){
			if(c[l]!=c[r]){
				ans+=a[r]-r1;
				l1+=a[r]-r1;
				r1=0;
				r--;
			}else{
				l1+=a[r]-r1;
				r1=0;
				r--;
			}
		}else{
			if(c[l]!=c[r]){
				ans+=a[l]-l1;
				r1+=a[l]-l1;
				l1=0;
				l++;
			}else{
				r1+=a[l]-l1;
				l1=0;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}

