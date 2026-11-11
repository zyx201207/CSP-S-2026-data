#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,ans;
string s;
struct edge{
	long long a;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	for(int i=1;i<=n;i++){
		while(a[i].a--){
			s+=a[i].c;
		}
	}
	for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
		if(s[i]!=s[j]) ans++; 
	}
	cout<<ans;
	return 0;
}
