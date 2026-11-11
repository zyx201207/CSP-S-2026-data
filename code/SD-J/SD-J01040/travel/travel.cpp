#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char e,f;
bool vis[200];
int n[5];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i='A';i<='C';i++){
		vis[i]=1;
	}
	if(a[0]==c[0]&&a[1]==c[1]){
		n[1]=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			n[2]=1;
			if(vis[b[2]]==vis[d[2]]){
				n[3]=1;
				if(abs(b[2]-d[2])==1){
					n[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<n[i];
	}
	return 0;
} 
