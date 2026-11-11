#include<bits/stdc++.h>
using namespace std;
int n,sum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out ","w",stdout);
	cin>>n;
	while(n--){
		char a;
		int b;
		cin>>b>>a;
		while (b--){
			s+=a;
		}
	}
	string s2;
	int l=s.size();
	for(int i=l-1;i>(l-1)/2;i--){
		char a=s[i];
		s2+=a;
	}
	for(int i=0;i<(l-1)/2;i++){
		if(s2[i]!=s[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
