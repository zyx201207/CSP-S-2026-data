//Devloped By MingDynasty (8:37-9:05)
//Luogu UID:1015347 & 1625468
//My Website:https://www.mgdyqwq.com
#include<bits/stdc++.h>
using namespace std;
int n,a[323232],pos;
char c[323232];
bool flag;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
//	if(a[1]<a[2]) flag=1;
//	else flag=2;
	int ans=0;
	for(int i=1;i<=n/2;i++){
//		if(c[n-i+1]!=c[i]){
//			if(a[n-1+1]==a[i]) ans+=a[n-i+1];
//			else ans+=max(a[n-i+1],a[i]);
//		}else{
//			if(a[n-i+1]!=a[i]) ans+=abs(a[n-i+1]-a[i]);
//		} 
		if(a[n-i+1]!=a[i]){
			if(c[i]!=c[n-i+1]){
				ans+=a[i];
				if(a[i]>a[n-i+1]){
					a[n-i]-=(a[i]-a[n-i+1]);
					a[n-i+1]+=(a[i]-a[n-i+1]);
				}
			}
		}
		else if(c[i]!=c[n-i+1]) ans+=a[i];
	}
	cout<<ans;
	return 0;
}
