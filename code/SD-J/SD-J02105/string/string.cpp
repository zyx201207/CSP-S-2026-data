#include<bits/stdc++.h>
using namespace std;
long long n,a[2000011],qqq[2000011],s,lcd,l=1,r;
char b[2000011],www[2000011];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>qqq[i]>>www[i];
		if(www[i]==www[i-1]){
			a[lcd]+=qqq[i];
		}
		else {
			lcd++;
			a[lcd]=qqq[i];
			b[lcd]=www[i];
		}
	}
	r=lcd;
	for(long long i=1;l<r;i++){
		if(b[l]==b[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else {
				a[l]-=a[r];
				r--;
			}
		}
		else {
			if(a[l]==a[r]){
				s+=a[l];
				l++;
				r--;
				
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				s+=a[l];
				l++;
				
			}
			else {
				a[l]-=a[r];
				s+=a[r];
				r--;
			}
		}
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<s;
	return 0;
}
