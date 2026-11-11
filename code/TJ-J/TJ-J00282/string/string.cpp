#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
string c[200005];
string pp="";
long long l=0,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		while(a[i]--){
			pp=pp+c[i];
		}
	}
	for(int i=l-1;i>=l/2+1;i--){
		if(pp[i]!=pp[l-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	
	
	return 0;
}
