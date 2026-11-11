#include<bits/stdc++.h>
using namespace std;
long long a,sum,n,i;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	n=s.size()-1; 
	while(i<=n-i){
		if(s[i]!=s[n-i])sum++;
		i++;
	}
	cout<<sum;
	return 0;
}
