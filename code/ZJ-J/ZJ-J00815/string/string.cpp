#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],l,r,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;l=1;r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}for(int i=1;i<n;i++){
		if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++;r--;i++;
			}else{
				ans+=a[l];
				l++,r--,i++;
			}
		}else if(a[l]>a[r]){
			if(c[l]==c[r]){
				a[l]-=a[r];r--;
			}else{
				ans+=a[r];
				a[l]-=a[r];r--;
			}
		}else if(a[l]<a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[l];
				a[r]-=a[l];l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
