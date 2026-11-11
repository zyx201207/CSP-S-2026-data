#include<bits/stdc++.h>
using namespace std;
int n;
char c;
long long a;
string s;
long long num;
long long ant;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a;
		cin>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
		num+=a;
	}
	num=num/2;
	long long l=0,r=s.size();
	for(int i=0;i<num;i++){
		if(s[l]!=s[r]){
			ant++;
		}
		l++;
		r--;
	}
	cout<<ant;
	return 0;
}
