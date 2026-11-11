#include<bits/stdc++.h>
using namespace std;
int n;
long long q[200005],L,mid,cnt;
struct node{
	long long l,r,len;
	char c;
}s[200005];

long long cntl(long long x){
	return L-x+1;
}

void work(){
	int i=1,j=n;
	while(1){
		if(s[i].l>=mid || cntl(s[j].r)>=mid) break;
		if(i==j) break;
		if(s[i].c!=s[j].c){
			cnt+=max(0ll,(min(mid,min(s[i].r,cntl(s[j].l)))-max(s[i].l,cntl(s[j].r))+1));
		}
		if(s[i].r>cntl(s[j].l)) --j;
		else if(s[i].r<cntl(s[j].l)) ++i;
		else {++i;--j;}
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		char k;
		scanf("%lld%c%c",&s[i].len,&k,&s[i].c);
		s[i].l=s[i-1].r+1;
		s[i].r=s[i].l+s[i].len-1;
		q[i]=q[i-1]+s[i].len;
	}
	L=q[n];
	if(L%2==1) mid=(L+1)>>1;
	else mid=L>>1;
	work();
	printf("%lld",cnt);
	return 0;
}