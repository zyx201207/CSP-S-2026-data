#include<bits/stdc++.h>
using namespace std;
string q,w;
int e,r,y,u;
char t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>e;
	for(int i=0;i<e;i++){
		cin>>r>>t;
		for(int j=0;j<r;j++){
			q[y]=t;
			y++;
		}
	}
	for(int i=0;i<e;i++){
		w[i]=q[y-i];
		if(w[i]!=q[i])u++;
	}
	cout<<u/2;
	return 0;
}
