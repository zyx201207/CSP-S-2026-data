#include<bits/stdc++.h>
using namespace std;
bool flag[10];
int side[6]={0,0,0,1,-1,1};
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		flag[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			flag[2]=1;
			int sider=side[s1[2]-'A'],sidex=side[s2[2]-'A'];
			if(sider==sidex){
				flag[3]=1;
				if(sider==0&&abs((s1[2]-'A')-(s2[2]-'A'))==1||sider==1){
					flag[4]=1;
				}
			}
		}
	}
	cout<<flag[1]<<flag[2]<<flag[3]<<flag[4];
	return 0;
}

