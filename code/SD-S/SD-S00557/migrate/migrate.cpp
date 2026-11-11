#include <bits/stdc++.h>
using namespace std;

#define igate(x,y) for(int i=(x);i<=(y);i++)
#define jgate(x,y) for(int j=(x);j<=(y);j++)
#define rev_igate(x,y) for(int i=(x);i>=(y);i--)
#define rev_jgate(x,y) for(int j=(x);j>=(y);j--)
#define int ll
typedef long long ll;
typedef pair<int,int> P;

const int N=5e2+10,M=5e5+10;
int mod=998244353,inf=0x3f3f3f3f3f3f3f3f;
int ID;


int lowbit(int x){ return x&(-x);
}

int n,d;
int a[N],pre[N];
int fj[N],bj[N];
int siz[N];
vector<int>bjt[N];

void frontjump(int i){
	if(i==n||a[i+1]-a[i]>d){
		
		fj[i]=0;
		
		return ;
	}
	int l=i+1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(pre[mid]-pre[i]<=d)l=mid;
		else r=mid-1;
	}fj[i]=l;
	
	return ;
}
void backjump(int i){
	if(i==1||a[i]-a[i-1]>d){
		
		bj[i]=0;
		
		return ;
	}
	int l=1,r=i-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(pre[i]-pre[mid]<=d)r=mid;
		else l=mid+1;
	}bj[i]=r;
	
	return ;
}

void Main(){
	
	
	cin>>n>>d;
	igate(1,n){
		siz[i]=1;
		bjt[i].clear();
	}
	pre[1]=0;
	igate(1,n){
		cin>>a[i];
		if(i>1)pre[i]=pre[i-1]+(a[i]-a[i-1]);
	}
	igate(1,n){
		frontjump(i); if(fj[i])siz[fj[i]]+=siz[i];
		backjump(i); if(bj[i])bjt[bj[i]].push_back(i);
		
		//cout<<fj[i]<<' '<<bj[i]<<endl;
	}
	
	int res=0;
	igate(1,n-1){
		if(bj[i]&&fj[bj[i]]&&fj[bj[i]]==i+1){
			int cnt=0;
			for(auto var:bjt[i]){
				
				if(var>i+1)cnt++;
				
			}
			
			res+=siz[bj[i]]*cnt;
		}
	}
	
	cout<<res<<endl;
}
signed main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int T;cin>>ID>>T;
	igate(1,T){Main();
	}
	
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/
