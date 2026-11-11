#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
bool f=false;
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				l++;
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
		}else if(c[l]!=c[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}
		}	
//		if(f) break;
//		if(l+1==r) f=true;
	}
	cout<<ans;
	return 0;
}
