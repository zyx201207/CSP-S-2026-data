#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
//struct trie{
//	int tree[N<<5][2],num[N<<5],tt;
//	void push(int a){
//		int x=0;
//		++num[0];
//		for(int i=30;i>=0;i--){
//			int now=(a&(1<<i));
//			if(now)now=1;
//			cout<<now<<' ';
//			if(!tree[x][now])tree[x][now]=++tt;
//			x=tree[x][now];
//			++num[x];
//		}
//		cout<<'\n';
//	}
//	int query(int k){
//		int ans=0,x=0,cnt=30;
//		while(num[x]>=k&&cnt>=0){
////			cout<<x<<' '<<tree[x][1]<<' '<<tree[x][0]<<' '<<num[tree[x][1]]<<'\n';
//			if(tree[x][1]&&num[tree[x][1]]>=k){
//				ans+=(1<<cnt);
//				x=tree[x][1];
//			}else if(!tree[x][0])return ans;
//			else x=tree[x][0];
//			--cnt;
//		}
//		return ans;
//	}
//	void get(){
//		for(int i=0;i<=tt;i++)cout<<tree[i][0]<<' '<<tree[i][1]<<' '<<num[i]<<'\n';
//	}
//}T;
int n,k,a[N];
//struct TA{
//	int tree[N];
//	void add(int pos,int x){
//		while(pos<=n){
//			tree[pos]+=x;
//			pos+=pos&(-pos);
//		}
//	}
//	int sum(int pos){
//		int ans=0;
//		while(pos){
//			ans+=tree[pos];
//			pos-=pos&(-pos);
//		}
//		return ans;
//	}
//}T[40];ÎÒÊÇÉµ×Ó 
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ed=n,ans=0;
	for(int i=30;i>=0;i--){
		int sum=0,x=(1<<i);
		for(int i=1;i<=ed;i++)if(a[i]&x)++sum;
		if(sum>=k){
//			cout<<i<<' '<<ed<<'\n';
			ans+=(1<<i);
			while((a[ed]&(1<<i))==0)--ed;
		}else{
			for(int j=1;j<=ed;j++)if(a[j]&x)a[j]-=(1<<i);
			sort(a+1,a+ed+1,cmp);
		}
	}
	cout<<ans;
	return 0;
}
/*
   CCC          CCC     FFFF
  C            C        F
  C            C        FFFF
  C            C        F
   CCC hinese   CCC an  F    ly
*/
