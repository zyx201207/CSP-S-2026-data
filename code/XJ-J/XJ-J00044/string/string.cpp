#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	long long n,a;
	cin>>n;
	string s,s1;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>s1;
		for(int j=1;j<=a;j++){
			s+=s1;
		}
	}
	string s2;
	long long b1=s1.size(),b2=s1.size();
	if(b1%2==0){
		b1/=2;
		for(int k=b2-1;k>b1;k++){
			s2+=s1[k];
			cout<<s2;
		}
	}else if(b1%2==1){
		b1/=2;
	}
	return 0;
}

