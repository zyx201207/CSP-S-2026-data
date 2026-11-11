#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
long long n,x,cnt;
char y;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			s+=y;
		}	
	}for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
