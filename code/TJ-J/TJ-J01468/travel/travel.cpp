#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	bool f1=1,f2=1,f3=1; 
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			f1=0;
			cout<<0;
			break;
		}
	}
	if(f1) cout<<1;
	if(f1){
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				f2=0;
				cout<<0;
				break;
			}
		}
		if(f2) cout<<1;		
	}else{
		cout<<0;
		f2=0;
	}

	if(f2){
		if(s1[2]=='A'){
			if(s2[2]=='B'||s2[2]=='C'){
				cout<<1;
			}else{
				cout<<0;
				f3=0;
			}
		}else if(s1[2]=='B'){
			if(s2[2]=='A'||s2[2]=='C'){
				cout<<1;
			}else{
				cout<<0;
				f3=0;
			}
		}else if(s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'){
				cout<<1;
			}else{
				cout<<0;
				f3=0;
			}
		}else if(s1[2]=='D'){
			if(s2[2]=='F'){
				cout<<1;
			}else{
				cout<<0;
				f3=0;
			}
		}else if(s1[2]=='F'){
			if(s2[2]=='D'){
				cout<<1;
			}else{
				cout<<0;
				f3=0;
			}
		}		
	}else{
				cout<<0;
				f3=0;
	}

	if(f1&&f2&&f3){
		if(s1[2]=='A'&&s2[2]=='B'){
			cout<<1;
		}else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
			cout<<1;
		}else if(s1[2]=='C'&&s2[2]=='B'){
			cout<<1; 
		} else if(s1[2]=='D'&&s2[2]=='F'){
			cout<<1; 
		} else if(s1[2]=='F'&&s2[2]=='D'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}//fkw
	return 0;
} 
