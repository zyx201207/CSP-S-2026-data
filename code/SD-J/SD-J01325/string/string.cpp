#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],l,r,ans=0;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			a[l]-=a[r];
			if(c[l]!=c[r]){
				ans+=a[r];
			}r--;
		}else if(a[l]<a[r]){
			a[r]-=a[l];
			if(c[l]!=c[r]){
				ans+=a[l];
			}l++;
		}else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}l++;
			r--;
		}
	}cout<<ans;
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
