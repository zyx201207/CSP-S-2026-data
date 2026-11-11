#include<bits/stdc++.h>;
using namespace std;
int a,b;
string s,t;
bool f=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>t;
	if(a==b){
		cout<<1;
		int c,d;
		for(int i=0;i<s.size()-1;i++){
			if(s[i]==t[i])	f=true;
			else	f=false;
		}
		if(f==true)	cout<<1;
		else cout<<0;
		char n,m;
		n=s[2];
		m=t[2];
		if(f==true){
			if(m<='C'&&n<='C'){
				cout<<1;
				if(m>n){
					if(m-1==n) cout<<1;
					else cout<<0;
				}
				else{
					if(n-1==m) cout<<1;
					else cout<<0;			
				}
			}
			else if(m>='D'&&n>='D'){
				cout<<1;
				if(m>n){
					if(m-1==n) cout<<1;
					else cout<<0;
				}
				else{
					if(n-1==m) cout<<1;
					else cout<<0;			
				}
			}
			else{
				cout<<0;
				cout<<0;
			}		
		}
		else{
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
