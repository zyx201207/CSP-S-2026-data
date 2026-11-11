#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",in);
	freopen("string.out","w",out);
	string m,x;
	int n，sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			m+=c[i];
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=a[i];j++){
			x+=c[i];
		}
	}
	if(m==x) cout<<"0";
	else{
		for(int i=0;i<m.size();i++){
			if(m[i]!=x[i]) sum++;
		}
	}cout<<sum;
	return 0;
}