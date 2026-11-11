#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1,c2,s2,q1,q2,p1,p2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<s1.size()-1;i++){
		q1+=s1[i];
	}
	for(int i=0;i<s2.size()-1;i++){
		q2+=s2[i];
	}
	for(int i=2;i<s1.size();i++){
		p1+=s1[i];
	}
	for(int i=2;i<s2.size();i++){
		p2+=s2[i];
	}
	int l1=s1[2],l2=s2[2];
	if(c1==c2){
		cout<<1;
		if(q1==q2){
			cout<<1;
			if(p1==p2||(p1=="A"&&(p2=="B"||p2=="C"))||(p1=="B"&&(p2=="A"||p2=="C"))||(p1=="C"&&(p2=="B"||p2=="A"))||(p1=="D"&&p2=="F")||(p1=="F"&&p2=="D")){
				cout<<1;
				if(abs(l1-l2)<=1||((p1=="D"&&p2=="F")||(p1=="F"&&p2=="D"))){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			} 
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}

