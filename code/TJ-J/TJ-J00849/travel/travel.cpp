#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,n1;
	string m,m1;
	cin>>n>>m>>n1>>m1;
	if(n==n1){
		cout<<1;
		if(m[0]==m1[0] and m[1]==m1[1]){
			cout<<1;
			if((m[2]>='D' and m1[2]>='D') or m[2]<='C' and m1[2]<='C'){
				cout<<1;
				if((m[2]+1==m1[2] or m[2]-1==m1[2]) and (m[2]!='C' and m1[2]!='D') and (m[2]!='D' and m1[2]!='C'))cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
}
