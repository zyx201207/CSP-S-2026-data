#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define s1isA s1[2]=='A'
#define s2isA s2[2]=='A'
#define s1isB s1[2]=='B'
#define s2isB s2[2]=='B'
#define s1isC s1[2]=='C'
#define s2isC s2[2]=='C'
#define s1isD s1[2]=='D'
#define s2isD s2[2]=='D'
#define s1isF s1[2]=='F'
#define s2isF s2[2]=='F'
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				cout<<1;
				// 
				if((s1isA||s2isA)&&(s2isB||s1isB)){
						cout<<1;
				}else if((s1isB||s2isB)&&(s2isC||s2isC)){
						cout<<1;
				}else if((s1isD||s2isD)&&(s2isF||s1isF)){
						cout<<1;
				}else cout<<"0";
				//
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
/*

打了半天判断条件终于过了累死我了 
*/
