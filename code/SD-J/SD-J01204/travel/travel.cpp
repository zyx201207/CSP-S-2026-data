#include<bits/stdc++.h>
using namespace std;
int a,b;
int c,d;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>a>>c>>x>>b>>d>>y;
	if(a==b){
		cout<<'1';
		if(c==d){
			cout<<'1';
			if(x<='C'&&y<='C'||x>='D'&&y>='D'){
				cout<<'1';
				if(int(x)+1==int(y)||int(x)-1==int(y)){
					cout<<'1';
				}
				else{
					cout<<'0';
				}
			}
			else{
				cout<<'0'<<'0';
			}
		}
		else{
			cout<<'0'<<'0'<<'0';
			return 0;
		}
	}
	else{
		cout<<'0'<<'0'<<'0'<<'0';
	}
	return 0;
} 
