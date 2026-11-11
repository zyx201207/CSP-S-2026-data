//王彦龙 庆安初级中学 SN-J00629 
#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2; cin>>c1>>s1>>c2>>s2;
	
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	
	int p1=0,p2=0; char l1,l2;
	
	for(int i=0;i<s1.size();i++){
		if('0'<=s1[i] && s1[i]<='9') p1=p1*10+s1[i]-'0';
		else l1=s1[i];
	}
	
	for(int i=0;i<s2.size();i++){
		if('0'<=s2[i] && s2[i]<='9') p2=p2*10+s2[i]-'0';
		else l2=s2[i];
	}
	
	if(p1!=p2){
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	
	if((0<=l1-'A' && l1-'A'<=2 && 0<=l2-'A' && l2-'A'<=2) || (3<=l1-'A' && l1-'A'<=4 && 3<=l2-'A' && l2-'A'<=4)) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	
	if(abs((l1-'A')-(l2-'A'))<=1) cout<<"1";
	else cout<<"0";
	
	return 0;
	
}
