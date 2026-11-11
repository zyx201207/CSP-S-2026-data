#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string c_1,s_1,c_2,s_2;
bool ans_1,ans_2,ans_3,ans_4;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c_1>>s_1>>c_2>>s_2;
	
	if(c_1 == c_2){
		ans_1 = 1;
	}
		
	if(ans_1 && s_1[0]==s_2[0] && s_1[1]==s_2[1]){
		ans_2 = 1;
	}
	
	if(ans_2 && ((s_1[2]<='C' && s_2[2]<='C')||(s_1[2]>'C' && s_2[2]>'C')))
		ans_3 = 1;

	if(ans_3 && (s_1[2]==s_2[2]+1 || s_1[2]==s_2[2]-1))
		ans_4 = 1;
	
	cout<<ans_1<<ans_2<<ans_3<<ans_4;
	return 0;
}

