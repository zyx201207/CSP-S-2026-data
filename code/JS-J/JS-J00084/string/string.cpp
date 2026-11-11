#include<bits/stdc++.h>
using namespace std;
long long num;
char ch;
string st;
int n;
int check(string a){
	long long l=0,r=a.length()-1;
	long long ans=0;
	while(l<r){
		if(a[l]!=a[r])ans++;
		l++;
		r--;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>ch;
		for(int j=1;j<=num;j++){
			st+=ch;
		}
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	cout<<check(st);
	return 0;
}
