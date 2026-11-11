#include<bits/stdc++.h>
#define endl '\n'
#define int int64_t
//int8_t buf[1<<20],*p1,*p2;
//#define getchar() ((p1==p2&&p2=(p1=buf)+fread(buf,1,1<<20,stdin)&&(*p2=EOF)),*p1++)
//int read(){int k=0,f=1;int c=getchar();for(;c<'0'||c>'9';c=getchar()){if(c=='-'){f=-1;}}for(;c>='0'&&c<='9';c=getchar()){k=k*10+(c-'0');}return k*f;}
using namespace std;
int n,m,a[200010],ans;
vector<int>v;
void turn(int x){
	vector<int>nv; 
	for(int i:v){
		if(a[i]&(1<<x)) nv.push_back(i); 
	}
	if(nv.size()>=m){
		ans|=(1<<x);
		v=nv;
	}
}
int32_t main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v.push_back(i);
	}
	for(int i=30;i>=0;i--){
		turn(i);
	}
	cout<<ans<<endl;
	return 0;
}
