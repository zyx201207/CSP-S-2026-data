#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int c1c=int(c1[0]-'0')*10+int(c1[1]-'0');
	int c2c=int(c2[0]-'0')*10+int(c2[1]-'0');
	int s1s=int(s1[0]-'0')*10+int(s1[1]-'0');
	int s2s=int(s2[0]-'0')*10+int(s2[1]-'0');
	int a1=int(s1[2]);
	int a2=int(s2[2]);
	if(c1c!=c2c){
		cout<<"0000";
	}else{
		cout<<1;
		if(s1s!=s2s){
			cout<<"000";
		}else{
			cout<<1;
			if((a1<68&&a2<68)||(a1>=68&&a2>=68)){
				cout<<1;
				if(a1-a2==1&&a2!=67){
					cout<<1;
				}else if(a2-a1==1&&a1!=67){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
}

