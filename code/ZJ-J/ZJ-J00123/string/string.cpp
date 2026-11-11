#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],b[200005];
int n;
long long ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		char c;
		cin>>c;
		b[i]=c-'a';
	}
	int head=n+1,tail=0;
	long long nwnum=0,nwp=-1;
	while(head!=tail){
		if(nwnum<=0){
			--head;
			if(b[head]!=nwp)ans-=max(nwnum,-a[head]);
			nwnum+=a[head];
			if(nwnum>0)nwp=b[head];
		}else {
			++tail;
			if(b[tail]!=nwp)ans+=min(a[tail],nwnum);
			nwnum-=a[tail];
			if(nwnum<=0)nwp=b[tail];
		}
	}
	cout<<ans;
	return 0;
}
