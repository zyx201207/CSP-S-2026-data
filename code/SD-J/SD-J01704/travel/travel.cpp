#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char k[8]={'k','A','B','C',' ','D','F','k'};
	string l1,l2,s1,s2;
	cin>>l1>>l2>>s1>>s2;
	if(l1==s1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	char a=l2[0],b=l2[1],c=s2[0],d=s2[1];
	if(a==c&&b==d){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(int(l2[2])<=67&&s2[2]<=67||l2[2]>=68&&s2[2]>=68){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	int f=0;
	for(int i=1;i<=6;i++){
		if(l2[2]==k[i]){
			if(k[i-1]==s2[2]||k[i+1]==s2[2]){
				cout<<1; 
			}else cout<<0;
		}
	}
	return 0;
} 
