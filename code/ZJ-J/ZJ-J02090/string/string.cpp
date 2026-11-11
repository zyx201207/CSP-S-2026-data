#include <bits/stdc++.h>
using namespace std;

string s;
int n;
long long m;
char a;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>m>>a;
		s += (m,a);
	}
	
	long long ans = s.size();
	const double N = s.size()/2+1;
	for(int j=0; j < N; j++){
		if(s[j] == s[s.size()-j]){
			if(j+2 >= N && s.size()%2 != 0) ans--;
			else ans -= 2;
		}
	}
	cout<<ans/2;
	
	return 0;
}
