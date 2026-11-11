#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
		if(a1[0]*10+a1[1]==b1[0]*10+b1[1]){
			cout<<1;
			if(a1[2]<='C'&&b1[2]>='D'||b1[2]<='C'&&a1[2]>='D'){
				cout<<"00";
			}else{
				cout<<1;
				if(abs(a1[2]-b1[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
