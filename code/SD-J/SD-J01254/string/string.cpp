#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	long long sum=0;
	while(n--){
		int a;
		cin>>a;
		string p;
		cin>>p;
		for(int i=1;i<=a;i++){
			s+=p;
		}
	}
	long long len=s.size()-1;
	long long i=0;
	for( i=0;i<len/2+1;i++){
			if(s[i]!=s[len-i]){
				s[i]=s[len-i];
				sum++;
			}
		}
	cout<<sum;
	return 0;
}


