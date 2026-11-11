#include<bits/stdc++.h>
using namespace std;
string s;
long long sum=0;
long long n,a;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s.push_back(c);
		}
	}
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
