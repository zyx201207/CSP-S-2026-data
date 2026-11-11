# include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,s1,c2,s2,c3,c4;
	char s3,s4;
	cin>>c1>>s1>>c2>>s2;
	c3=s1[0]+s1[1];
	s3=s1[2];
	s4=s2[2];
	c4=s2[0]+s2[1];
	int a,b;
	if(s4=='A'||s4=='B'||s4=='C'){
		a=1;
	}else{
		a=0;
	}
	if(s3=='A'||s3=='B'||s3=='C'){
		b=1;
	}else{
		b=0;
	}
	if(c1==c2){
		cout<<1;
		if(c3==c4){
			cout<<1;
			if(a==b){
				cout<<1;
				if(abs(s3-s4)==1||s3=='F'||s4=='F'){
					cout<<1;
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
	
	
	
	
	return 0;
}
