#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin >> n;
	for(int i=0;i<n;i++){
		long long int a;
		char c;
		cin >> a >> c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	long long int zf=0;
	long long int p=s.length();
	p=p/2;
	if(s.length()%2==1){
		for(int i=1;i<=p;i++){
			if(s[p+i]!=s[p-i]){
				zf++;
			}
		}
		cout << zf;
		return 0;
	}
	else{
		for(int i=1;i<=p;i++){
			if(s[p-i]!=s[p+i-1]){
				zf++;
			}
		}
		cout << zf;
		return 0;
	}
}