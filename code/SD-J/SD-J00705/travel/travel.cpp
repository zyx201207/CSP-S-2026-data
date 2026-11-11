#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,aa,b,bb; 
char aaa,bbb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(aa[2]=='D') aa[2]='E';
	if(bb[2]=='D') bb[2]='E';
	aaa=aa[2];
	bbb=bb[2];
	if(a==b){
		cout<<"1";
		if(aa[0]==bb[0] && aa[1]==bb[1]){
			cout<<"1";
			ll ad,bd;
			if(aaa=='A' || aaa=='B' || aaa=='C'){
				ad=0;
			}else ad=1;
			if(bbb=='A' || bbb=='B' || bbb=='C'){
				bd=0;
			}else{
				bd=1;
			}
			if(ad==bd){
				cout<<"1";
				if(aaa>bbb){
					swap(aaa,bbb);
				}
				if((int)(bbb-aaa)==1){
					cout<<"1";
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
//luogu_liuyuxiaozaizai

