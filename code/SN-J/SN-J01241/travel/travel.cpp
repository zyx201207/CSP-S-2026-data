#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	int n,m;
	string a,b;
	cin>>n>>a>>m>>b;
	if(n==m){
		cout<<"1";
		if(a[0]==b[0] and a[1]==b[1]){
			cout<<"1";
			if(a[2]+b[2]==131 || a[2]+b[2]==132 ||a[2]+b[2]==133 || a[2]+b[2]==138){
				cout<<"1";
				if(a[2]+1==b[2]+1-1 || a[2]-1==b[2]+1-1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			} 
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	freopen("travel.out","w",stdout);
} 
