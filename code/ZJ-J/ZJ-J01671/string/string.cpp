#include<bits/stdc++.h>
#define endl '\n'
#define int int64_t
//int8_t buf[1<<20],*p1,*p2;
//#define getchar() ((p1==p2&&p2=(p1=buf)+fread(buf,1,1<<20,stdin)&&(*p2=EOF)),*p1++)
//int read(){int k=0,f=1;int c=getchar();for(;c<'0'||c>'9';c=getchar()){if(c=='-'){f=-1;}}for(;c>='0'&&c<='9';c=getchar()){k=k*10+(c-'0');}return k*f;}
using namespace std;
int n,L,ans;
string s="";
int32_t main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	L=s.size();
	s=' '+s;
	for(int i=1;i<=L/2;i++){
		if(s[i]!=s[L+1-i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

