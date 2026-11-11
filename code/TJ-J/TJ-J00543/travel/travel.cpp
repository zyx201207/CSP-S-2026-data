#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string c1,c2,s1,s2;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f1=1;
		string ss1=s1.substr(0,2),ss2=s2.substr(0,2);
		if(ss1==ss2){
			f2=1;
			char a1=s1[2],a2=s2[2];
			if(a1=='D'&&a2=='F'){
				f3=1,f4=1;
			}
			else{
				if(a1=='A'&&a2=='B'||a1=='B'&&a2=='A'){
					f3=1,f4=1;
				}
				if(a1=='C'&&a2=='B'||a1=='B'&&a2=='C'){
					f3=1,f4=1;
				}
				if(a1=='A'&&a2=='C'||a1=='C'&&a2=='A'){
					f3=1;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4<<'\n';
	return 0;
}

