#include<bits/stdc++.h> 
using namespace std;
string s;
int n,m;
char x;
int q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>x;
		while(m--){
			s=s+x;
		}
	}
	int n=s.size();
	int nx=(n+1/2)-1;
	for(int i=0;i<=nx;i++){
		if(s[i]!=s[n-i-1]){
			q++;
		}
	}
	cout<<q;
	return 0;
}
