#include<iostream>
#define int long long
using namespace std;

struct{
	int a;
	char c;
}n[200005];
int N;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin>>N;
	for(int i=1;i<=N;i++)cin>>n[i].a>>n[i].c;
	int ia=1,ib=N;
	int ans=0;
	while(ia<ib){
		if(n[ia].a<n[ib].a){
			if(n[ia].c!=n[ib].c)ans+=n[ia].a;
			n[ib].a-=n[ia].a;
			ia++;
		}else if(n[ia].a>n[ib].a){
			if(n[ia].c!=n[ib].c)ans+=n[ib].a;
			n[ia].a-=n[ib].a;
			ib--;
		}else if(n[ia].a==n[ib].a){
			if(n[ia].c!=n[ib].c)ans+=n[ia].a;
			ia++;
			ib--;
		}
	}cout<<ans<<endl;
}
