#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
int num1(int n){
	string s;
	int k;
	while(n>1){
		if(n%2==1){
			s+='1';
		}
		else{
			s+='0';
		}
		n=n/2;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			k++;
		}
	}
	return k;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(num1(a[j])<num1(a[j+1])){
				swap(a[j],a[j+1]);
			}
		}
	}
	ans=a[0];
	for(int i=1;i<m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
