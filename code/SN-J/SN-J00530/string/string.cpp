#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt;
char q;
string s;
bool flag=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>q;
		for(int i=0;i<a;i++){
			s+=q;
		}
	}
	string b;
	b=s;
	if(s==b){
		cout<<0;
		return 0;
	}
	long long r=0;
	while(r<=(s.size()-1)/2){
		if(s[r]!=b[r]){
			cnt++;
		}
		r++;
	}
	cout<<cnt;
	return 0;
}
