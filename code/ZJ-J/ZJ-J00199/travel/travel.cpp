#include<bits/stdc++.h>
using namespace std;
int n,m,f1,f2,f3,f4;
string s1,s2,S1,S2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s1>>m>>s2;
	if(n==m){
		f1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f2=1;
			if(int(s1[2])<=int('C')&&int(s2[2])<=int('C')||int(s1[2])>=int('D')&&int(s2[2])>=int('D')){
				f3=1;
				if(int(s1[2]+1)==int(s2[2])||int(s1[2])==int(s2[2]+1))
					f4=1;
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}