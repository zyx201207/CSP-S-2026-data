#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct node{
	int num,yi,wei;
}a[maxn];
int n,m;
void f(int k){
	int q=a[k].num,ans=0,ans1=0;
	while(q){
		if(q%2!=0)ans++;
		q/=2,ans1++;
	}
	a[k].yi=ans,a[k].wei=ans1;
}
bool cmp(node a,node b){
	if(a.yi!=b.yi)return a.yi>b.yi;
	else if(a.yi==b.yi)return a.wei>b.wei;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		f(i);
	}
	sort(a+1,a+n+1,cmp);
	int qw=a[1].num;
	for(int i=2;i<=m;i++)
		qw&=a[i].num;
	cout<<qw;
	return 0;
}
