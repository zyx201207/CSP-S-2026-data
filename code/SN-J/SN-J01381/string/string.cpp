#include<bits/stdc++.h>
using namespace std;
string s;
string s1;
int sum;
int ss(int a,char b){
	for(int j=1;j<=a;j++){
			s+=b;
	}
	return 0;
}
int sss(int a){
	for(int i=a-1;i>=0;i--){
		s1+=s[i];
	}
}
int ssss(int a){
	for(int i=0;i<a;i++){
		if(s[i] != s1[i]){
			sum++;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		ss(m,c);
	}
	sss(s.size());
	if(s==s1){
		cout<<0<<endl;
		return 0;
	}else{
		ssss(s.size());
	}
	cout<<sum/2<<endl;
	return 0;
}
