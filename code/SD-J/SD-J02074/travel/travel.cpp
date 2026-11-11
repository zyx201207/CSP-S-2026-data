#include<bits/stdc++.h>
using namespace std;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]) a[1]=1;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])a[2]=1;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')a[3]=1;
		else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&s1[2]!='E'&&s2[2]!='E'){
			a[3]=1;
		}else a[3]=0;
	}
	int sum1=(c1[0]-'0')*10+int(c1[1]-'0'),sum2=(c2[0]-'0')*10+int(c2[1]-'0');
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&s1[2]!='E'&&s2[2]!='E'){
		if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
			if(s1[2]-'A'+1==s2[2]-'A'||s1[2]-'A'-1==s2[2]-'A')a[4]=1;		
		}else a[4]=0;
	}else a[4]=0;
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}
