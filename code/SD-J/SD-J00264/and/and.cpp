#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	int id;
}bit[200010];
long long a[200010];
//
long long lowbit(long long x){
	return x&(-x);
}
long long bit_num(long long x){
	long long ans=0;
	while(x>0){
		x-=lowbit(x);
		ans++;
	}
	return ans;
}
bool cmp(node xx,node yy){
	if(xx.num==yy.num){
		return a[xx.id]>a[yy.id];
	}
	return xx.num>yy.num;
}
//
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bit[i].num=bit_num(a[i]);
		bit[i].id=i;
	}
	sort(bit+1,bit+n+1,cmp);
	long long ans=a[bit[1].id];
	for(int i=1;i<=m;i++){
		ans=ans&a[bit[i].id];
	}
	cout<<ans;
	return 0;
}

