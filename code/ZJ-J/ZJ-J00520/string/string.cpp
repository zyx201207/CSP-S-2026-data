#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=2e5+5;
int n;
struct node{
	int cnt;
	char ch;
}a[N];
int sum;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].ch;
		sum+=a[i].cnt;
	}
	sum/=2;
	int l=1,r=n,c1=0,c2=0,ans=0;
	while(l<=r){
		if(c1==sum&&c2==sum)break;
		int x1=0,x2=0;
		if(c1+a[l].cnt>=sum){
			x1=sum-c1;
		}
		else{
			x1=a[l].cnt;
		}
		if(c2+a[r].cnt>=sum){
			x2=sum-c2;
		}
		else{
			x2=a[r].cnt;
		}
		int tot=min(x1,x2);
		c1+=tot;
		c2+=tot;
		if(a[l].ch!=a[r].ch)ans+=tot;
		a[l].cnt-=tot;
		a[r].cnt-=tot;
		if(!a[l].cnt)l++;
		if(!a[r].cnt)r--;
	}
	cout<<ans<<"\n";
} 

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	system("fc string.out string6.ans");
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
/*
100pts
*/
