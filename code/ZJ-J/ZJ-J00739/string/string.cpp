#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200100],t;
char c[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]==a[r]){
				t+=a[l];
				l++;
				r--;
			}
			else if(a[l]>a[r]){
				t+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				t+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<t;
	return 0;
}
