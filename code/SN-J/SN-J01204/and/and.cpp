#include<iostream>
#define  int  long long
using namespace std;
constexpr int N=2e5+5;
bool Beg;

int n,m,a[N];

bool check(int x){
	int Cnt=0;
	for(int i=1;i<=n;i++)
		if((a[i]&x)==x)Cnt++;
	return (Cnt>=m);
}

bool End;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int L=0,R=1<<30,mid;
	while(L+1<R){
		mid=(L+R)>>1;
		if(check(mid))L=mid;
		else R=mid;
	}
	cout<<L<<'\n';
	cerr<<(&Beg-&End)/1024.0/1024.0<<" MB\n";
	return 0;
}
