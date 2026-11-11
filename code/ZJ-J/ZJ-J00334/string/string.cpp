#include<iostream>
#include<string>
#define int long long
using namespace std;
struct Node{
	long long l,r,cnt;
	char s;
}node[200005];
int n;
long long cnt=0;
char finds(long long x){
	for(int i=1;i<=n;i++)if(node[i].l<=x&&x<=node[i].r)return node[i].s;
}
long long findcnt(long long x){
	for(int i=1;i<=n;i++)if(node[i].l<=x&&x<=node[i].r)return node[i].cnt;
}
long long L;
long long diff(){
	long long ans=0;
	for(int i=0,j=cnt-1;i<=j;){
		if(finds(i)==finds(j)){
			long long res=min(findcnt(i),findcnt(j));
			if(i+res+1>j-res-1)return ans;
			else i=i+res,j=j-res;
		}else{
			long long res=min(findcnt(i),findcnt(j));
			i=i+res,j=j-res;
			ans+=res;
		}
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char s;
		cin>>x>>s;
		node[i].l=L;
		node[i].r=L+x;
		node[i].cnt=x;
		node[i].s=s;
		L=L+x+1;
		cnt+=x;
	}
	cout<<diff();
}
