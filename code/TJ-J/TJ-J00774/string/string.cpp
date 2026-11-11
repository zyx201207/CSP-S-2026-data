#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string c;
	int n;
	long long num=0;
	cin>>n;
	long long a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n/2;i++){
	    if(c[i]!=c[n-i-1]){
	    	num=num+a[i];
	    	if(a[n-i-1]%2==1){
	    		num=num-1;
			}
		}
	}
	cout<<num;
	return 0;
}
