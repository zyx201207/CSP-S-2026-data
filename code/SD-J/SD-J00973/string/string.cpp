#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	long long int ans=0;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r--];
			}else if(a[l]<a[r]){
				a[r]-=a[l++];
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r--];
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l++];
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}
	} 
	cout<<ans;
	return 0;
}
