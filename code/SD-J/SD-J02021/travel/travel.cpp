#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int r1,f1;
bool flag=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>c1>>s1>>c2>>s2;
	for(int i=c1.size()-1;i>=0;i--){
		r1=r1+(c1[i]-'0')*pow(10,c1.size()-1-i);
	}for(int i=c2.size()-1;i>=0;i--){
		f1=f1+(c2[i]-'0')*pow(10,c2.size()-1-i);
	}if(f1==r1){
		cout<<1;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				flag=0;
				break;
			}
		}if(flag){
			cout<<1;
			if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]<'D'&&s2[2]!='D'&&s2[2]!='F')){
				cout<<1;
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
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
