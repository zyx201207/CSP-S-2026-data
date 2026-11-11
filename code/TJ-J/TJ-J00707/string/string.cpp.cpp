//▓т╩╘╡у▒р║┼ n б▄ maxn
//i=1 ai 
//1 1
//5
//2 бл 4 2
//5, 6
//10
//1
//7, 8 50
//9
//2 000
//1
//10 бл 12 50
//13 бл 16 109
//17, 18
//2 б┴ 105
//1
//19 бл 21 500
//22 бл 25 109

#include <bits/stdc++.h>
using namespace std;

long long n,a,cnt;
string s;
string b;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++) {
    	cin>>a>>b;
	}
	for(long long i=0;i<a;i++) {
    	s=s+b;
	}
	for(long long i=s.length();i>=0;i++) {
		s1[(s.length()-i)]=s[i];
	}
	for(long long i=0;i<=s.length();i++) {
		if(s[i]==s1[i]) {
			cnt++;
		}
	}
	cout<<cnt/2-1;
	return 0;
} 
