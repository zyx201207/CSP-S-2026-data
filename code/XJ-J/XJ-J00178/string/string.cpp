#include<bits/stdc++.h>
using namespace std;
long long a,s[10000000],w=0;
string q,e,r; 
int main(){
	preopen("string.in","r",stdin);
    preopen("string.out","w",stdout);
	cin>>a;
    for(int i=1;i<=a;i++){
    	cin>>s[i]>>q[i];
	}for(int i=1;i<=q.length();i++){
		for(int j=i;j<=s[i];j++){
			e[i]=s[i];
		}for(int j=i;j<=s[i];j++){
			e[i]=s[i];
		}for(int j=i;j<=s[i];j++){
			e[i]=s[i];
		}
	}for(int i=1;i<=e.length();i++){
		if(e[i]!=e[e.length()-i]){
			w++;
		}
	}cout<<w;
	return 0;
} 
