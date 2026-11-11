#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string x;
		cin>>a>>x;
		for(int j=1;j<=a;j++){
			s=s+x;
		}
	}
	int i=0,j=s.size()-1;
	while(i<j){
		if(s[i]!=s[j]){
			m++;
		}
		i++;j--;
	}
	cout<<m;
	return 0;
}