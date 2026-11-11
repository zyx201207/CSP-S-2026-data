#include <bits/stdc++.h>
using namespace std;
int n;
string s="";
struct hw{
	int a;
	char c;
}h[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i].a>>h[i].c;

	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=h[i].a;j++){
			s+=h[i].c;
		}
	}
	int l=s.size();
	int cnt=0;
		for(int i=1;i<l;i++){
			if(s[i]!=s[l-i]){
				cnt++;

			}
		}
	cout<<cnt;

	return 0;
}
