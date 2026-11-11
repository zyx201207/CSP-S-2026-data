#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<'1';
		ans++;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<'1';
			ans++;
			if((b[2]=='A'&&d[2]=='B')||(b[2]=='A'&&d[2]=='C')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
				cout<<'1';
				ans++;
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
					cout<<'1';
					ans++;
				}else{
					cout<<'0';
					ans++;
				}
			}else{
				cout<<'0';
				ans++;
			}			
		}else{
			cout<<'0';
			ans++;
		}		
	}else{
		cout<<'0';
		ans++;
	}
	if(ans==0){
		cout<"0000";
	}else if(ans==1){
		cout<<"000";
	}else if(ans==2){
		cout<<"00";
	}else if(ans==3){
	cout<<'0';
	}
	return 0;
} 
