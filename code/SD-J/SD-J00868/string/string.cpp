#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans,k;
char c[200010]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0]=-1;c[0]='!';
	for(int i=1;i<=n;i++){
		k++;
		cin>>a[k]>>c[k]; 
		if(c[k]==c[k-1]){
			a[k-1]+=a[k];
			k--;
		}
	}
	long long l=1,r=k;
	while(l<=r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}	
			a[r]-=a[l];
			l++;
		}else if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}else if(a[l]==a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++;r--;
		}
	}
	cout<<ans;
	return 0;
}
