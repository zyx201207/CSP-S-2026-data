#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	char a,b,m,n;
	char f,r,o,p;
	cin>>a>>m>>f;
	if(a==m){
			for(char c:b){
				if(c>"0"&&c<"9"){
					f = f+c;
				}
			} 
			for(char c:n){
				if(c>"0"&&c<"9"){
					r = r+c;
				}
			if(f==r){
				for(char c:b){
					if(c>"A"&&c<"G"){
						o = o+c;
				}
			} 
				for(char c:n){
					if(c>"A"&&c<"G"){
						p = p+c;
				}
				if(p=="C"&&o=="D"||0=="C"&&p=="D"){
					cout<<"1100";
				}
				else{
					if(p+1=o||p-1=o){
						cout<<"1111";
					else{
						cout<<"1110";
					}
					}
				}
			}
		}
		else{
			cout<<"1000";
		}
		}
	else{
		cout<<"0000"
	}
	return 0; 
}
