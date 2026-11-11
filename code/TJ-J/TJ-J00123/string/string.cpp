#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	int a=0;
	string s;
	cin >> n ;
	for(int i=0; i<=n; i++){
		cin >> s[i];
	}
	for(int i=0; i<=s.size()/2+1; i++){
		if(s.size()%2!=0){
			if(s[s.size()-i]!=s[s.size()+i]){
				s[s.size()+i]=s[s.size()-i];
				a++;
			}
				
		}
		else{
			if(s[s.size()-i]!=s[s.size()+i+1]){
				s[s.size()+i+1]!=s[s.size()-i];
				a++;
			}
		}
	}
	cout << a;
	return 0;
}
