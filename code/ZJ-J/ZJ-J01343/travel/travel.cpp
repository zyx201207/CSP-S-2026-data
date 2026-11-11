#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int s;
bool fl[11]={0,0,0,0,1,1,1};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		s++;
		if(r2[0]==x2[0]&&r2[1]==x2[1]){
			s++;
			if(fl[int(r2[2]-'A')+1]==fl[int(x2[2]-'A')+1]){
				s++;
				if(abs(r2[2]-x2[2])==1)s++;
			}
		}
	}
	for(int i=1;i<=s;i++)cout<<1;
	for(int i=s+1;i<=4;i++)cout<<0;
}