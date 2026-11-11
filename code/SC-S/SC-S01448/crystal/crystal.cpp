#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int,int> PII;
typedef array<int,3> ar;
const int N=5e5+5;
int n,m,a[N],pre[N],ma;
bool ch(int mi,int i){
	int cha=a[i]*(i-mi)-(pre[i]-pre[mi]);
	return cha<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	ma=1;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		int l=0,r=i,an=0;
		while(l<=r){
			int mid=l+r>>1;
			if(ch(mid,i)) an=mid,r=mid-1;
			else l=mid+1;
		}
		ma=max(i-an,ma);
		//if(i-an==2) cout<<i<<'*';
	}
	cout<<ma;
	return 0;
}