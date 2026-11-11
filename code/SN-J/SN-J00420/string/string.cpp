#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,a,m;
    cin>>n;
    string e,s="";
    for(int i=0;i<n;i++){
    	cin>>a>>e;
    	s+=e[i];
    	m+=a;
	}
	if(s[0]==s[1]){
		cout<<s;
	} 
	return 0;
}  
