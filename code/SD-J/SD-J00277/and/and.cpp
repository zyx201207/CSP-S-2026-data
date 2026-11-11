#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int n,m;
struct Node{
	int v;
	bool f;
}a[MAXN];
bool f[MAXN];
int key=0;
bool cmp(Node A,Node B){
	if(A.f==B.f)return A.v>B.v;
	return A.f>B.f;
} 
int ans=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].v,a[i].f=true;
	for(int i=30;i>=0;i--){
		ans<<=1;
		for(int j=1;j<=n;j++)a[j].v&=(1ll<<i+1)-1;
		sort(a+1,a+n+1,cmp);
		if((a[m].v)>>i&1){
			ans++;
			for(int j=m+1;j<=n;j++){
				if(a[j].v>>i&1)continue;
				if(a[j].f==false)break;
				a[j].f=false;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

