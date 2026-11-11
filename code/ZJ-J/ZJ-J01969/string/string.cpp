#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int x;
char s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		cin>>s1;
		for(int j=1;j<=x;j++){
			s+=s1;
		}
	}
	int sum=0;
	if(s.size()%2){
		int x=(s.size()-1)/2;
		for(int i=x+1;i<s.size();i++){
			if(s[i]!=s[2*x-i]){
				sum++;
			}
		}
	}else{
		int x=s.size()/2;
		for(int i=x;i<=s.size();i++){
			if(s[i]!=s[i-(i-x)*2-1]){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}