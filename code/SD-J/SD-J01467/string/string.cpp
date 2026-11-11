#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n;
long long a[N];
string c[N];
long long cnt=0;
long long ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	} 
	long long l=1,r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			if(a[l]<a[r]){
				cnt+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				cnt+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			} 
			else{
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<cnt<<"\n";
	return 0;
} 
//24104423
