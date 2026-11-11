#include<bits/stdc++.h>
using namespace std;
long long n,m,shu=0,o;
char a;
string s;
int main(){
	long long j=1;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		o+=m;
		for(int p=1;p<=m;p++){
			s[j]=a;
			j++;
		}
		
	}
	for(int i=1;i<=n/2+1;i++){
		if(s[i]!=s[o]){
			s[j]=s[i];
			o--;
			shu++;
		}
	}
	cout<<shu;		
	return 0;
}