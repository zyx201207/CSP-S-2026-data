#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[10],sum=0;
	string c,s,s1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int i=0;i<a[i];i++){
			s[i]=c[i];
		}
	}
	
	for(int i=0;i<s.length();i++){
		s1=s[i]-'0'/10;
		s[i]-'0'%10;
	}
	
	if(==s1){
		cout<<sum;
	}else{
		sum++;
	}
    return 0;
}
