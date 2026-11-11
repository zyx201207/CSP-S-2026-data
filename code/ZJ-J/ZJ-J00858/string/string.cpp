#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long a[200005];
char c[200005];
int f(string s){
	int L=0,R=s.size()-1,ans=0;
	while(L<R){
		if(s[L]!=s[R]){
			ans++;
		}
		L++;
		R--;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(long long j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	if(f(s)==0){
		cout<<0;
		return 0;
	} 
	cout<<f(s);
	return 0;
}

