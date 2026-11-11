#include<bits/stdc++.h>
using namespace std;
int n=0;
int y=0;
long long a[222222],m1=0,ans=0,m=1,i1=1,i2=1;
char c,b[222222];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
		cin>>b[i];
	}
	//cout<<n/2<<endl;
	if(n%2!=0){
		y=n/2+1;
	}else{
		y=n/2;
	}
	for(int i=1;i<=y;i++){
		//cout<<b[i1]<<b[n+1-i2]<<endl;
		if(b[i1]!=b[n+1-i2]){
			if(a[i1]>a[n+1-i2]){
				ans+=a[n+1-i2];
				a[i1]-=a[n+1-i2];
				i2++;
			}else if(a[i1]==a[n+1-i2]){
				ans+=a[i1];
				//cout<<2;
				i1++;
				i2++;
			}else{
				ans+=a[i1];//cout<<3;
				a[n+1-i2]-=a[i1];
				i1++;
			}

		}else if(b[i1]==b[n+1-i2]){
				if(a[i1]>a[n+1-i2]){
					a[i1]-=a[n+1-i2];
					i2++;
				}else if(a[i1]==a[n+1-i2]){
					i1++;
					i2++;
				}else {
					a[n+1-i2]-=a[i1];
					i1++;
				}
			}
	}
	cout<<ans;
    return 0;
}
