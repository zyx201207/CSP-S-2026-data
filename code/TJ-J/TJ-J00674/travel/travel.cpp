#include<bits/stdc++.h>
using namespace std;
int y[][2]={{5,4},{4,5},{1,2},{1,3},{2,1},{2,3},{3,1},{3,2}};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]!=s2[0] || s1[1]!=s2[1]){
		cout<<"000";
		return 0; 
	}
	cout<<1;
	int c=s1[2]-'A'+1,s=s2[2]-'A'+1;
	for(int i=0;i<8;i++){
		if(c==y[i][0] && s==y[i][1]){
			cout<<1;
			if(i==3 || i==6)
				cout<<0;
			else
				cout<<1;
			return 0;
		}
	}
	cout<<"00";
	return 0;
}
