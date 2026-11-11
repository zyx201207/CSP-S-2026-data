#include<bits/stdc++.h>
using namespace std;
long long n,m,e,r;
string s;
char d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m>>d;
		for(long long j=1;j<=m;j++){
			s[r]=d;
			r++;
		}
	}
	for(long long i=0,j=r-1;i<r/2;i++,j--){
		if(s[i]!=s[j]){
			e++;
		}
//		cout<<s[i]<<' '<<s[j]<<endl;
	}
	cout<<e;
	return 0;
} 
