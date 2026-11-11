#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;
int l1,r1,l2,r2;
int ans1,ans2,ans3,ans4;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	l1=(s1[0]-'0')*10+(s1[1]-'0');
	if(s1[2]=='F')s1[2]='E';
	r1=s1[2]-'A';
	l2=(s2[0]-'0')*10+(s2[1]-'0');
	if(s2[2]=='F')s2[2]='E';
	r2=s2[2]-'A';
	ans1=(c1==c2);
	ans2=(ans1)&&(l1==l2);
	ans3=(ans2)&&(r1<=2 && r2<=2 || r1>2 && r2>2);
	ans4=(ans3)&&(abs(r2-r1)==1);
	cout<<ans1<<ans2<<ans3<<ans4<<endl;
	return 0;
} 
