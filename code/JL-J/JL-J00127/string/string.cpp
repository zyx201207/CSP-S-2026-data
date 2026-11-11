#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[100005],ans=0;
	char c[100005];
	cin>>n;
	for(int i=1;i<=2*n;i+=2){
		cin>>a[i];
		cin>>c[i];
	}for(int i=2*n-1;i>=1;i-=1){
		int k=1;
		if(c[i]!=c[k]){
			ans+=a[i];
			c[i]=c[k];
			if(c[i]<c[k]){
				ans+=a[k]-a[i];
				a[i-2]-=a[k]-a[i];
				a[i-1]=a[k];
				c[i-1]=c[k];
				ans--;
				
			}			
		}k+=1;
	}cout<<ans;
	return 0;
}
