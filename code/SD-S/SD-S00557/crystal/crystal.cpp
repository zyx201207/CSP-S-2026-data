#include <bits/stdc++.h>
using namespace std;

#define igate(x,y) for(int i=(x);i<=(y);i++)
#define jgate(x,y) for(int j=(x);j<=(y);j++)
#define rev_igate(x,y) for(int i=(x);i>=(y);i--)
#define rev_jgate(x,y) for(int j=(x);j>=(y);j--)


const int N=5e5+10,M=2e2+10;
int mod=998244353;
typedef long long ll;
typedef pair<int,int> P;
#define int ll

int lowbit(int x){ return x&(-x);
}

int n,m;
int a[N];

__int128 tre[N];
void add(int x,int val){
	while(x){
		tre[x]+=val;
		x-=lowbit(x);
	}
}
int ask(int x){
	__int128 res=0;
	while(x<=n){
		res+=tre[x];
		
		x+=lowbit(x);
	}
	return res;
}
void sadd(int l,int r,int val){
	add(r,val);
	if(l-1>0)add(l-1,-val);
}

void Main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	
	cin>>n>>m;
	
	igate(1,n){
		cin>>a[i];
	}sort(a+1,a+n+1);
	
	int ans=1,j=1,sum=0;
	igate(2,n){
		
		sum+=(a[i]-a[i-1])*(i-j);
		add(i-1,a[i]-a[i-1]);
		;
		
		while(sum>m&&j<=i){
			sum-=ask(j);
			j++;
		}
		
		ans=max(ans,i-j+1);
	}
	
	cout<<ans<<endl;
}
signed main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	Main();
	
	return 0;
}
/*
5 5
1 2 4 8 9
5 10
-5 -7 20 3 3
*/
