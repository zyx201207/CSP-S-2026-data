#include<bits/stdc++.h>
using namespace std;
int n,m,u1,q; string s,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>d;
		while(m--){
			s+=d;
		}	
	}
	int u1=s.size();
	for(int i=0;i<u1/2;i++){
		if(s[i]!=s[u1-i-1]){
			q+=1;
		}
	}
	if(q>0){
		cout<<q;
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}