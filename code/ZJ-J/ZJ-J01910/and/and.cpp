#include<bits/stdc++.h>
using namespace std;
long long n,m,f;
string s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	while(cin>>s){
		f++;
		if(f==n){
			cout<<s;
		}
	}
	return 0;
}
