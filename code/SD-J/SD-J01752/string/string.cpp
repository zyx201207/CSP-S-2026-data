#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10;
//Trick||Treat!
int n,cnt=0;
struct ST{
	int a;
	int vis;
	char s;
}c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].a>>c[i].s;
		c[i].vis=c[i].a;
	}
	for(int i=1,j=n;i<=j;){
		if(c[i].vis==c[j].vis){
			if(c[i].s!=c[j].s)cnt+=c[i].vis;
//			c[i].vis=c[j].vis=0;
			i++,j--;
		}
		else if(c[i].vis<c[j].vis){
			if(c[i].s!=c[j].s)cnt+=c[i].vis;
			c[j].vis-=c[i].vis;
			i++;
			
		}
		else if(c[i].vis>c[j].vis){
			if(c[i].s!=c[j].s)cnt+=c[j].vis;
			c[i].vis-=c[j].vis;
			j--;
			
		}
//		cout<<cnt<<' '<<i<<' '<<j<<'\n';
	}
	cout<<cnt;
	return 0;
}

