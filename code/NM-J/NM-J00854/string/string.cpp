#include<bits/stdc++.h>
using namespace std;
long long a[2000001];
long long b;
char c[2000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b+=a[i];
	}
	if(b%2==1) b++;
	b/=2;
	long long l=1,r=n,cnt=0;
	while(l<=r){
		if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++,r--;
				continue;
			}else{
				cnt+=a[l];
				l++,r--;
				continue;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				if(c[l]!=c[r]){
					cnt+=a[r];
				}
				r--;
			}else{
				a[r]-=a[l];
				if(c[l]!=c[r]) cnt+=a[l];
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
