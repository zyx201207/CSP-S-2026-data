#include<bits/stdc++.h>

using namespace std;
long long n;
struct zxcvbnm{
	long long a;
	char c;
}str[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i].a>>str[i].c;
	}
	//int flag=1;
	//for(int i=1;i<n;i++){
	//	if(str[i].c==str[i+1].c){
	//		flag=1;
	//	}else{
	//		flag=0;
	//	}
	//}
	//if(flag){
	//	cout<<0;
	//	return 0;
	//}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=str[i].a;j++){
			s+=str[i].c;
		}
	}
	long long sum=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]!=s[n+1-i]){
			sum++;
		}
	}
	cout<<sum/2;
	return 0;
}
