#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,cnt,tmp,mid;
struct node{
	int t;
	char c;
}a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].c;
		cnt+=a[i].t;
	}
	cnt=(cnt+1)/2;
	for(int i=1;i<=n;i++){
		tmp+=a[i].t;
		if(tmp>=cnt){
			mid=i;
			break;
		}
	}
	int l=1,r=n,nl=a[1].t,nr=a[n].t;
	while(l<mid||r>mid){
		if(nl>nr){
			ans+=nr*(a[l].c!=a[r].c);
			nl-=nr;
			nr=a[--r].t;
		}else if(nl<nr){
			ans+=nl*(a[l].c!=a[r].c);
			nr-=nl;
			nl=a[++l].t;
		}else{
			ans+=nr*(a[l].c!=a[r].c);
			nr=a[--r].t;
			nl=a[++l].t;
		}
	}
	cout<<ans;
	return 0;
}
