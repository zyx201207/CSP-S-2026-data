#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	int c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int h=0;
	for(int i=0;i<n-1;i++){
		if(c[i]==c[i+1]) h++;
	}
	if(h==n-1) cout<<"0";
	return 0;
}
