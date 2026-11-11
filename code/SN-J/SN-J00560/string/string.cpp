#include<bits/stdc++.h>
using namespace std;
int n,a,sum;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s+=c;
		}
	}
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]) sum++;
	}
	cout<<sum;
	return 0;
	
}
