#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+5;
int a[N],b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	queue<int>q;
	sort(a+1,a+n+1);
	int res=0,ans=-1;
	for(int i=1;i<n;i++){
		int cha=a[i+1]-a[i];
		int add=cha*(q.size()+1);
		m-=add;
		q.push(a[i]);
		res++;
		while(m<0){
			m+=a[i+1]-q.front();
			q.pop();
			res--;
		}
		ans=max(ans,res);
	}
	cout<<ans+1;
	return 0;
}
//5 10
//-1000 -999 -10 0 9
