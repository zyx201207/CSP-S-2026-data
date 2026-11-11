#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	long long a[n+5];
	char c[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			a[i-1]+=a[i];
			n--;
		}
	}
	long long gai=0;
	for(int i=1;i<=n;i++){
		if(c[i]==c[n]){
			if(a[i]>a[n]){
				a[i]-=a[n];
				n--;
				i=i-1;
			}
			else if(a[i]==a[n]){
				a[i]=0;a[n]=0;
				n--;
			}
			else {
				a[n]-=a[i];
				a[i]=0;
			}
		}
		else {
			gai+=min(a[n],a[i]);
			if(a[i]>a[n]){
				a[i]-=a[n];
				a[n]=0;
				n--;
				i=i-1;
			}
			else if(a[i]==a[n]){
				a[i]=0;a[n]=0;
				n--;
			}
			else {
				a[n]-=a[i];
				a[i]=0;
			}
		}
	}
	cout<<gai;
	return 0;
}