#include<bits/stdc++.h>
using namespace std;
long long n,a[200009],ans,su;
char c[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		su+=a[i];
	}
	for(long long j=0,q=n,p=1,i=a[p];i<=su/2;p++,i+=a[p]){
		if(i!=a[p]&&i>=j&&c[p]!=c[q+1]){
			ans+=j-i+a[p];
		}
		while(j<i){
			j+=a[q];
			if(j<=i){
				if(c[q]!=c[p]){
					ans+=a[q];
				}
			}
			q--;
		}
		if(j>i){
			if(c[q+1]!=c[p]){
				ans+=i-j+a[q+1];
			}
		}
	}
	cout<<ans;
	return 0;
}
