#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long ans=0,l=1,r=n;
	while(l<r){
		long long j=min(a[l],a[r]);
		if(b[l]==b[r]){
			if(a[l]<a[r]){
				l+=1,a[r]-=j;
			}else if(a[l]>a[r]){
				r-=1,a[l]-=j;
			}else{
				l+=1,r-=1;
			}
		}else{
			ans+=j;
			if(a[l]<a[r]){
				l+=1,a[r]-=j;
			}else if(a[l]>a[r]){
				r-=1,a[l]-=j;
			}else{
				l+=1,r-=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
