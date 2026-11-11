#include<bits/stdc++.h>//×£ÎÒ¿ªÖÇ£¬ÓÀ²»±©Áã 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin >>c1 >> s1 >>c2 >> s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout << "1";
		bool a,b,c;
		a=b=c=false;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a=true;
			cout << "1";
			char q=s1[2];
			char p=s2[2];
			if((q=='F'&&p=='D')||(q=='D'&&p=='F')||(q=='C'&&p=='B')||(q=='B'&&p=='C')||(q=='A'&&p=='B')||(q=='B'&&p=='A')){
				cout << "11";
			}else if((q=='A'&&p=='C')||(q=='C'&&p=='A')){
				cout << "10";
			}else{
				cout <<"00"; 
			}
		}else{
			cout << "000";
		}
	}
	return 0;
}
