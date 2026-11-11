#include<bits/stdc++.h>
using namespace std;
const int N=100007;
int n,a[N],cnt,ans;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		cnt+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[i-1]){
			cout<<0;
			return 0;
		}
	}
	if(cnt%2==0){
		for(int i=0;i<cnt/2;i++){
			if(b[1+i]!=b[n-i]){
				if(a[1+i]=a[n-i]){
					ans=a[1+i]+a[n-i];
				}
			}			
		}

	}else{
		for(int i=0;i<(cnt-1)/2;i++){
			if(b[1+i]!=b[n-i]){
				if(a[1+i]=a[n-i]){
					ans=a[1+i]+a[n-i];
				}
			}			
		}
	}
	cout<<ans;
	return 0;
}
