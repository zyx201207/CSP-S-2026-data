#include<bits/stdc++.h>
using namespace std;
int main()
{
//	std::ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_X,c_R,s_X,s_R;
	cin>>c_R>>s_R>>c_X>>s_X;
	if(c_R==c_X){
		cout<<"1";
		if(s_R[0]==s_X[0]&&s_R[1]==s_X[1]){
			cout<<"1";
			if((s_R[2]<='C'&&s_X[2]<='C')||(s_R[2]>='D'&&s_X[2]>='D')){
				cout<<"1";
				if((s_R[2]==s_X[2]+1)||(s_X[2]==s_R[2]+1)) cout<<"1\n";
				else cout<<"0\n";
			}
			else cout<<"00\n";
		}
		else cout<<"000\n";
	}
	else cout<<"0000\n";
	return 0;
}
