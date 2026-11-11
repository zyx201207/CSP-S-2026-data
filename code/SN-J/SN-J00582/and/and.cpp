#include<bits/stdc++.h>
using namespace std;
int a[100005];

string r,r2;
int R(int n){
	while(n<=1){
		r+=n%=2;
		

}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	int m;
	for(int i=1;i,=n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<=n;i++){
		r2[i]=r[i]&r[i+1];
	} 
	for(int i=1;i<=r2.length();i++){
		m=max(r2[i],r2[i+1]);
	}
	cout<<m;
	return 0;
} 
