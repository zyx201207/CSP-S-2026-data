#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
		string t1=c2,t2=s2;
		t1.pop_back(),t2.pop_back();
		if(t1==t2){
			cout<<1;
			string l1="",l2="";
			l1+=c2[2],l2+=s2[2];
			if((l1=="A"&&(l2=="B"||l2=="C"))||(l1=="B"&&(l2=="A"||l2=="C"))||(l1=="C"&&(l2=="A"||l2=="B"))||(l1=="D"&&l2=="F")||(l1=="F"&&l2=="D")){
				cout<<1;
				if((l1=="B"&&(l2=="A"||l2=="C"))||(l2=="B"&&(l1=="A"||l1=="C"))||(l1=="D"&&l2=="F")||(l1=="F"&&l2=="D")) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
