#include<bits/stdc++.h>
using namespace std;
//#define ll long long
struct Node{
	long long l,r;
	char c;
}p[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		p[i].l=p[i-1].r+1;
		long long d;
		cin>>d>>p[i].c;
		p[i].r=p[i-1].r+d;
	}
	long long j=1,k=p[n].r,ij=1,ik=n,ans=0;
	while(j<k){
		long long d=min(p[ij+1].l-j,k-p[ik-1].r);
		if(p[ij].c!=p[ik].c)ans+=d;
		j+=d;
		k-=d;
		if(j>p[ij].r)ij++;
		if(k<p[ik].l)ik--;
	}
	cout<<ans;
	return 0;
}
