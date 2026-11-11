#include<bits/stdc++.h>
using namespace std;
bool f[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string c_1,s_1,t_1,c_2,s_2,t_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	t_1=s_1.substr(0,2),t_2=s_2.substr(0,2);
	s_1.erase(0,2),s_2.erase(0,2);
	if (c_1==c_2){
		f[1]=1;
		if (t_1==t_2){
			f[2]=1;
			if (s_1[0]<='C'&&s_2[0]<='C'||s_1[0]>='D'&&s_2[0]>='D'){
				f[3]=1;
				if (abs(s_2[0]-s_1[0])==1) f[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++)
		cout<<f[i];
	return 0;
}

