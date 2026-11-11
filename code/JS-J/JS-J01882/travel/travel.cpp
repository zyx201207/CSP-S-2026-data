#include <bits/stdc++.h>
using namespace std;
void sw(char &c1,char &c2){
	char temp = c1;
	c1 = c2;
	c2 = temp;
}
bool check(char c1,char c2){
	if (c1 > c2) sw(c1,c2);
	if (c1 == 'D' && c2 == 'F') return true;
	if (c2 - c1 == 1) return true;
	return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    string t1 = "",t2 = "";
    for (size_t i = 0;i < 2;i++) t1 += s2[i];
    for (size_t i = 0;i < 2;i++) t2 += s4[i];
    char c1 = s2[2],c2 = s4[2];
    if (s1 == s3){
        cout<<1;
        if (t1 == t2){
			cout<<1;
			if ((c1 < 'D' && c2 < 'D') || (c1 >= 'D' && c2 >= 'D')){
				cout<<1;
				if (check(c1,c2)) cout<<1;
				else cout<<0;
			}else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
    }
    else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
