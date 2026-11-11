#include <bits/stdc++.h>
using namespace std;
char s1[4],s2[4];
int c1,c2;
bool flag=false,flag1=false,flag2=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<2;++i){
			if(s1[i]!=s2[i]){
				flag=false;
			}else{
				if(s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D') flag1=true;
				else if(s1[2]=='A' && s2[2]=='B' || s1[2]=='B' && s2[2]=='C'|| s1[2]=='A' && s2[2]=='C' || s1[2]=='C' && s2[2]=='A' ||  s1[2]=='B' && s2[2]=='A' || s1[2]=='C' && s2[2]=='B'){
					flag1=true;
					if(s1[2]=='A' && s2[2]=='C' || s1[2]=='C' && s2[2]=='A' || s1[2]=='A' && s2[2]=='D' || s1[2]=='A' && s2[2]=='F' || s1[2]=='D' && s2[2]=='A' || s1[2]=='F' && s2[2]=='A' || s1[2]=='B' && s2[2]=='D' || s1[2]=='B' && s2[2]=='F' || s1[2]=='F' && s2[2]=='B' || s1[2]=='D' && s2[2]=='B' || s1[2]=='C' && s2[2]=='D' || s1[2]=='C' && s2[2]=='F' || s1[2]=='D' && s2[2]=='C' || s1[2]=='F' && s2[2]=='C'){
						flag2=false;
					}else flag2=true;	
				}else flag1=false;	
			}
		}
		if(flag==true) cout<<1;
		else cout<<0;
		if(flag1==true) cout<<1;
		else cout<<0;
		if(flag2==true) cout<<1;
		else cout<<0;
	}else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
