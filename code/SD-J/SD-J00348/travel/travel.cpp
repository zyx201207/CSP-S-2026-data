#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int cnt1=0,cnt2=0;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		if(c1[i]==c2[i])cnt1++;
		if(s1[i]==s2[i])cnt2++;
	}
	if(cnt1==2)cout<<'1';
	else{
	cout<<"0000";
	return 0;
	} 
	if(cnt2==2)cout<<'1';
	else {
	cout<<"000";
	return 0;
	}
	int a1=s1[2]-'A';
	int a2=s2[2]-'A';
	if((a1<=2&&a2<=2)||(a1>=3&&a2>=3))cout<<'1';
	else {
	cout<<"00";
	return 0;
	}
	int z=1;
	if(a1==2&&a2==3||a1==3&&a2==2)
		z=0;
	if((a1-a2==1||a2-a1==1)&&z!=0)cout<<'1';
	else cout<<'0';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
