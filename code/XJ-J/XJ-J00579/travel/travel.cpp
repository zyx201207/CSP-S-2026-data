#include<bits\stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll n;
string s,y,a,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>x>>y;
	if(a==x){
		cout<<"1";
		ll o=1;
		for(int i=0;i<2;i++){
			if(s[i]!=y[i]){
				cout<<"0";
				o=0;
				break;
			}
		}
		if(o){
			cout<<"1";
			ll u=0,v=0;
			if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
				u=1;
				if(y[2]=='A'||y[2]=='B'||y[2]=='C'){
					v=1;
				}
			}
			if(u==v){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0";
		}
		
	}else{
		cout<<"000";
	}
	for(int i=0;i<3;i++){
			if(i<2){
				if(s[i]!=y[i]){
					cout<<"0";
					fclose(stdin);
	fclose(stdout);	
					return 0;
				}
			}else{
					if(s[i]=='A'&&y[i]!='B'){
						cout<<"0";
						fclose(stdin);
	fclose(stdout);	
						return 0;
					}
					if(s[i]=='B'&&y[i]!='C'&&y[i]!='A'){
						cout<<"0";
						fclose(stdin);
	fclose(stdout);	
						return 0;
					}
					if(s[i]=='C'&&y[i]!='B'){
						cout<<"0";
						fclose(stdin);
	fclose(stdout);	
						return 0;
					}
					if(s[i]=='D'&&y[i]!='F'){
						cout<<"0";
						fclose(stdin);
	fclose(stdout);	
						return 0;
					}
					if(s[i]=='F'&&y[i]!='D'){
						cout<<"0";
						fclose(stdin);
	fclose(stdout);	
						return 0;
					}
				}
		}
		cout<<"1";
	fclose(stdin);
	fclose(stdout);	
	return 0;
}