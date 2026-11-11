#include<bits/stdc++.h>
using namespace std;
struct st{
	long long a;char s;
}t[1000000];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>t[i].a>>t[i].s;
	long long l=1,r=n;
	while(l<r){
		int v=min(t[l].a,t[r].a);
		if(t[l].s!=t[r].s ){
			ans+=v;
			t[r].a-=v;t[l].a-=v;
			if(!t[r].a) r--;
			if(!t[l].a) l++;
		}else{
			t[r].a-=v;t[l].a-=v;
			if(!t[r].a) r--;
			if(!t[l].a) l++;
		}
	}cout<<ans;
	return 0;
}
