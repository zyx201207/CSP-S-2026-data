#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(i) i<<1
#define rs(i) i<<1|1
#define lowbit(x) x&-x
const int N=1e5+10;
const int M=5e5+10;
const int base=1e9+7;
const int base1=1e9+9;
string s1,c1,s2,c2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s1>>c1>>s2>>c2;
    if(s1!=s2){
		cout<<"0000";
	}else{
		bool ok=1;
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			ok=1;
		}else{
			ok=0;
		}
		bool ok2;
		if(c1[2]<='C'){
			if(c2[2]<='C'){
				ok2=1;
			}else{
				ok2=0;
			}
		}else{
			if(c2[2]<='C'){
				ok2=0;
			}else{
				ok2=1;
			}
		}
		ok2=ok2&&ok;
		bool ok3=ok2&&ok;
		if(ok3){
			if(c1[2]=='A'){
				if(c2[2]=='B'){
					ok3=1;
				}else{
					ok3=0;
				}
			}else if(c1[2]=='B'){
				if(c2[2]=='A'||c2[2]=='C'){
					ok3=1;
				}else{
					ok3=0;
				}
			}else if(c1[2]=='C'){
				if(c2[2]=='B'){
					ok3=1;
				}else{
					ok3=0;
				}
			}else if(c1[2]=='D'){
				if(c2[2]=='F'){
					ok3=1;
				}else{
					ok3=0;
				}
			}else{
				if(c2[2]=='D'){
					ok3=1;
				}else{
					ok3=0;
				}
			}
		}
		cout<<1<<ok<<ok2<<ok3;
	}
    return 0;
}
