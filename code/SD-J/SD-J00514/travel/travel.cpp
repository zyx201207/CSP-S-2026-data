#include<bits/stdc++.h>
using namespace std;
//#define int long long
//signed main()
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string id1,s1,id2,s2;
	cin>>id1>>s1>>id2>>s2;
	if(id1==id2){
		cout<<1;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<1;
		if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C')) cout<<1;
		else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')) cout<<1;
		else if(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B')) cout<<1;
		else if(s1[2]=='D'&&s2[2]=='F') cout<<1;
		else if(s1[2]=='F'&&s2[2]=='D') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
		if(s1[2]=='A'&&s2[2]=='B') cout<<1;
		else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')) cout<<1;
		else if(s1[2]=='C'&&s2[2]=='B') cout<<1;
		else if(s1[2]=='D'&&s2[2]=='F') cout<<1;
		else if(s1[2]=='F'&&s2[2]=='D') cout<<1;
		else cout<<0;
	}
	else cout<<"0000";
	return 0;
}

