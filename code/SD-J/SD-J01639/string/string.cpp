#include<bits/stdc++.h>
#define st string
using namespace std;
bool hui(st s,int n){
	int l,r;
	l=0;
	r=n-1;
	while(l<=r){
		if(s[l]!=s[r])
		{
			return 0;
		}
		l++;
		r--;
	}
	return 1;
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	st s;
	char m[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>m[i];
		for(int j=1;j<=a[i];j++){
			s+=m[i];
		}
	}
	if(hui(s,s.size())){
		cout<<"0";
	} 
	else{
		cout<<"no";
	}	
	return 0;
}
