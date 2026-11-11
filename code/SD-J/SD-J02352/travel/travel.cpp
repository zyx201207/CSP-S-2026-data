#include<iostream> 
#include<cstring>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	string wer;
	
	cin>>c1>>s1;
	cin>>c2>>s2;
	
	if(c1==c2){
		wer+='1';
	}else{
		cout<<"0000";
		return 0;
	}
	
	bool a=false;
	for(int i=0;i<=1;i++){
		if(s1[i]==s2[i]){
			a=true;
		}else{
			a=false;
		}
	}
	
	if(a){
		wer+='1';
	}else{
		cout<<wer<<"000";
		return 0;
	}
	
		bool b=false;
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			b=true;
			wer+='1';
		}else if(s1[2]=='D'||s1[2]=='E'&&s2[2]=='D'||s2[2]=='E'){
			b=true;
			wer+='1';
		}else{
			b=false;
			wer+='0';
		}
		if(b){
			if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
				cout<<wer<<"0";
				return 0;
			}
			if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='F'){
				wer+='1';
			}else{
				if(int(s1[2]-s2[2])==1||int(s2[2]-s1[2])==1){
					wer+='1';
				}else{
					wer+='0';
				}
			}
			
		}else{
			wer+='0';
		}
	
	cout<<wer;
	return 0;
}
