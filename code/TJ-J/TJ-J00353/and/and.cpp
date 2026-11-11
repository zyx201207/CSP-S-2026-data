#include<bits/stdc++.h> 
using namespace std;
int a[2005];
bool f(int a,int b){
	return a>b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,f);
	if(m==1){
		cout<<a[0];
	}
	return 0;
}
