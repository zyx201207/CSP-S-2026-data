#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	long long l;
	if(n%2==0) l=n/2;
	else l=n/2+1;
	long long ans=0,ed=n-1;
	for(int i=0;i<=l;i++){
		if(c[i]!=c[ed]){
			if(a[ed]<a[i]){
				ans+=a[i];
				long long cha=a[i]-a[ed];
				while(a[--ed]<cha){
					cha-=a[ed];
				}
				a[ed]-=cha;
			}
			if(a[ed]>a[i]){
				ans+=a[i];
				a[ed]-=a[i];
			}
			if(a[ed]==a[i]){
				ans+=a[i];
				ed--;
			}
		}
		else{
			if(a[ed]<a[i]){
				long long cha=a[i]-a[ed];
				ans+=cha;
				while(a[--ed]<cha){
					cha-=a[ed];
				}
				a[ed]-=cha;
			}
			if(a[ed]>a[i]) a[ed]-=a[i];
		}
	}
	cout<<ans;
	return 0;
}
