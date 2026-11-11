#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out ","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long cnt=0,l=0,ans=0,p78=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans+=a[i];
		p78+=i;
	}
	for(int i=1;i<=n;i++){
		if(ans==p78){
			cout<<0;
			return 0;
		}
		if(a[i]==a[i+1]||(a[i]+a[i+1])-s[i]==m){
			cnt=a[i];
			for(int j=1;j<i;j++){
				a[j]=cnt;
			}
			break;
		}
	} 
	for(int i=1;i<=n;i++){
		if(a[i]==cnt){
			l++; 
		}
	}
	cout<<l;
	return 0;
}