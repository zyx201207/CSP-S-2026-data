#include<bits/stdc++.h>
using namespace std;
long long a[10000091],c=0,d=0,n;
string s[10000091],t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
		c+=a[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l]<=a[r]){
			if(s[l]!=s[r]){
				d+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		else{
			if(s[l]!=s[r]){
				d+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
	}
	cout<<d;
	return 0;
}