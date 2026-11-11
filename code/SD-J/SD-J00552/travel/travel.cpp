#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1]) cout<<"1";
	else cout<<"0";
	if(s1[0]==s2[0] && s1[1]==s2[1]) cout<<"1";
	else cout<<"0";
	char a[3]={'A','B','C'};
	int f=0;
	for(int i=0;i<3;i++){
		if(s1[2]==a[i]) f+=1;
		if(s2[2]==a[i]) f+=1;
	}
	if(f==0 || f==2) cout<<"1";
	else cout<<"0";
	char b[6]={'A','B','C','E','D','F'};
	for(int i=0;i<6;i++){
		if(s1[2]==b[i] && (b[i+1]==s2[2] || b[i-1]==s2[2])){
			cout<<"1";
			break;
		}else if(s1[2]==b[i] && (b[i+1]!=s2[2] && b[i-1]!=s2[2])){
			cout<<"0";
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
