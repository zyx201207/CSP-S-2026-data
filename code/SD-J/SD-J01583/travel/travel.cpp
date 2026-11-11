#include<bits/stdc++.h>
using namespace std;
string c,cc,s,ss;
bool check(string t,string tt,int op){
	int a=t[2]-'A';
	int aa=tt[2]-'A';
	if(op==0){
		if(((a<=2)&&(aa<=2))||((a>2)&&(aa>2))) return true;
		else return false;
	}
	else{
		if((a<=2)&&(aa<=2)){
			int b=abs(a-aa);
			if(b==1) return true;
			else return false;
		}
		else if((a>2)&&(aa>2)){
			return true;
		}
		else return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<"1";
		if((s[0]==ss[0])&&(s[1]==ss[1])){
			cout<<"1";
			if(check(s,ss,0)){
				cout<<"1";
				if(check(s,ss,1)){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
