#include<bits/stdc++.h>
using namespace std;
int n,e[1001],c=0,x=0,g=0,h=0;
string q[1001],p[1001],w[1001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string d[n]; 
	for(int i=0;i<n;i++){
		cin>>e[i]>>d[i];
}
	for(int i=0;i<n;i++){
		for(int j=0;j<e[i];j++){
			q[j]=d[i];
			p[c]=q[j];
			w[c]=q[j];
			c++;
		}}
	for(int i=0;i<c;i++){
		p[i]=w[c-i-1];
	}
			for(int i=0;i<c;i++){
				if(w[i]==p[i]){
					h++;
				}else{
				if(w[i]!=p[i]){
						g++;
				}
				}
				
				}
			
			if(h==c){
				cout<<"0";
			}else{
				cout<<g/2;
			}
			return 0;
	}
