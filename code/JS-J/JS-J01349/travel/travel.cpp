#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n;
	string a,b;
	cin>>m>>a>>n>>b;
	if(m!=n){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(a[0]!=b[0]||a[1]!=b[1]){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			if(('A'<=a[2]&&a[2]<='C'&&'D'<=b[2]&&b[2]<='E')||('A'<=b[2]&&b[2]<='C'&&'D'<=a[2]&&a[2]<='E')){
				cout<<"00";
				return 0;
			}
			else{
				cout<<"1";
				if(abs(int(a[2]-b[2]))==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
		}
	}
	return 0;
}
