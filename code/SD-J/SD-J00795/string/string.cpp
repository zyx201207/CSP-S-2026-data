#include<bits/stdc++.h>
using namespace std;
long long n,a;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0;
	while(n--){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}	
	}
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len+1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
