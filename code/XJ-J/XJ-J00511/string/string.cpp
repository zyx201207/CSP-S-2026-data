#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0,b=0,bb=0;
char c;
string s;
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	b=s.size();
	bb=b/2;
	for(int i=0;i<bb;i++){
		for(int j=b-1;j>bb;j--){
			if(s[i]!=s[j]){
				ans++;
				i++;
			}
		}
	}
	cout <<ans;
	return 0;
}
