#include<bits/stdc++.h>
#define endl '\n'
#define int int64_t
//int8_t buf[1<<20],*p1,*p2;
//#define getchar() ((p1==p2&&p2=(p1=buf)+fread(buf,1,1<<20,stdin)&&(*p2=EOF)),*p1++)
//int read(){
//	int k=0,f=1;
//	int c=getchar();
//	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
//	for(;c>='0'&&c<='9';c=getchar()) k=k*10+(c-'0');
//	return k*f;
//}
using namespace std;
string c1,s1,c2,s2;
int32_t main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<'1';
	if(s1.substr(0,2)!=s2.substr(0,2)){
		cout<<"000";
		return 0;
	}
	cout<<'1';
	if((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C')){
		cout<<"00";
		return 0;
	}
	cout<<'1';
	if(abs((int)s1[2]-(int)s2[2])!=1){
//		cout<<"\n\n"<<abs((int)s1[2]-(int)s2[2])<<endl; 
		cout<<"0";
		return 0;
	}
	cout<<'1';
	return 0;
}

