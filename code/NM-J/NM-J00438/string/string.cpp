#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0;
	cin>>n;
	vector<long long>vec1;
	vector<char>vec2;
	for(long long i=0;i<n;i++){
		long long a=0;
		cin>>a;
		vec1.push_back(a);
		char c='0';
		cin>>c;
		vec2.push_back(c);
	}
	string s1;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<vec1[i];j++){
			s1+=vec2[i];
		}
	}
	string s2;
	for(long long i=s1.length()-1;i>=0;i--){
		s2+=s1[i];
	}
//	cout<<s1<<'\n'<<s2;
	long long m=0;
	for(long long i=0;i<s1.length()/2;i++){
		if(s1[i]!=s2[i]){
			m++;
		}
	}
	cout<<m;
	return 0;
}
//3
//2 a
//2 b
//1 c
//
//2
//2 a
//3 a
//
//6
//10000000 a
//10000000 a
//10000000 a
//10000000 b
//10000000 b
//10000000 b
