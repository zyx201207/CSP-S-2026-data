#include<bits/stdc++.h>
using namespace std;
long long n;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		} 
	}
	long long cnt=0;
	long long i=0,j=s.length()-1;
	while(i<j){
		if(s[i]!=s[j]){
			cnt++;
		}
		i++;
		j--;
	}
	cout<<cnt;
	return 0; 
}
