#include<bits/stdc++.h>
using namespace std;
long long l;
int ab(string s){
	int ans=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			ans++;
		}
	}
	return ans;
}
string s; 
int n,a[1000005];
char b[1000005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			l++;
			s+=b[i];
		}
	}
	cout<<ab(s);
	return 0;
} 
