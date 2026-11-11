#include<bits/stdc++.h>
#include <set>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,d;
	char sp;
	long long n,m;
	long long ma=-10086,many=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		cin>>d;
		for(int j=0;j<m;j++){
			s+=d;
		}
	}
	for(int i=0;i<s.size();i++){
		many=0; 
		sp=s[i];
		for(int j=0;j<s.size();i++){
			if(s[j]==sp){
				many++;
			}
		}
		if(many>ma)ma=many;
	}
	cout<<(n-ma)<<endl;
	return 0;
} 
