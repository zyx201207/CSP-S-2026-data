#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
string s1,s2,s3,s4;
bool ok1,ok2,ok3,ok4;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	ok1=(s1==s3);
	ok2=(s2[0]==s4[0]&&s2[1]==s4[1]);
	ok3=(s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D');
	ok4=(abs(s2[2]-s4[2])==1);
	cout<<ok1<<(ok1&&ok2)<<(ok1&&ok2&&ok3)<<(ok1&&ok2&&ok3&&ok4)<<"\n";
	return 0;
}

