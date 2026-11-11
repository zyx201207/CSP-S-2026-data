#include<iostream>
#include<cmath>
using namespace std;
long long n,x,cnt;
char a;
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>a;
		for(long long i=1;i<=x;i++){
			s+=a;
			t+=a;
		}
	}
	
	int j=s.size()-1;
	for(int i=0;i<s.size(),j>=0;i++,j--){
		t[j]=s[i];
	}
	for(long long i=0;i<s.size();i++){
		if(s[i]!=t[i]) cnt++;
	}
	cout<<cnt/2;
	return 0;
} 
 //abcd
//  0123

//  d
