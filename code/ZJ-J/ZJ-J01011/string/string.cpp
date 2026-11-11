#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
	    for(int j=1;j<=x;j++){
			s[j]=a;
		}
		k+=x;
	}
	int as=0;
	if(k<=1) cout<<0;
	else{
		for(int i=1;i<=k;i++){
		    if(s[i]!=s[k+1-i]){
		        as++;
			   	s[i]=s[k+1-i];
			} 
	    }
	cout<<as;
	}

	return 0;
}
