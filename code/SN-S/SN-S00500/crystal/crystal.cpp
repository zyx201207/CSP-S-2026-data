//SN-S00500 高梓焱 西安市第三中学 
#include<bits/stdc++.h>
using namespace std;
long long m;
int n,a[1000000],b[1000000];
int l(int a){
	long long t=0;
	for(int i=0;i<a;i++){
		t+=b[i]*(i+1);
	}
	if(t<=m){
		return a;
	}else{
		return l(a-1);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	int c=0;
	for(int i=0;i<n-1;i++){
		c+=b[i];
		if(c>m){
			c=i;
			break;
		}
	}
	cout<<l(n)+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
