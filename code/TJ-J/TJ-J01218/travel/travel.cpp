#include<bits/stdc++.h>
using namespace std;
string a,b,n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>a>>b>>n>>m;
	if(a==n){
		cout<<1;
		if(b[0]+b[1]==m[0]+m[1]){
		cout<<1;
			if(b[2]=='A'&&m[2]=='B'||m[2]=='C'){
				cout<<1;
			}else{
				if(b[2]=='B'&&m[2]=='A'||m[2]=='C'){
					cout<<1;
				}else{
					if(b[2]=='C'&&m[2]=='B'||m[2]=='A'){
						cout<<1;
						}else{
							if(b[2]=='D'&&m[2]=='F'||b[2]=='F'&&m[2]=='D'){
								cout<<1;
							}else cout<<"00";
					}
				}
			}
		}else{
			cout<<"000";
			return 0;
		}if(b[2]=='A'&&m[2]=='B'){
				cout<<1;
			}else{
				if(b[2]=='B'&&m[2]=='C'){
					cout<<1;
				}else{
					if(b[2]=='B'&&m[2]=='A'){
						cout<<1;
					}else{
						if(b[2]=='C'&&m[2]=='B'){
							cout<<1;
						}else{
							if(b[2]=='D'&&m[2]=='F'){
								cout<<1;
							}else{
								if(b[2]=='F'&&m[2]=='D'){
									cout<<1;
								}else{
									cout<<"0";
								}
							}
						}
					}
				}
			}
		}else{
			cout<<"0000";
			return 0;
		
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
