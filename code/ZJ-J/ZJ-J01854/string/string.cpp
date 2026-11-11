#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+5;
struct node{
	int l,r;
	char c;
}t1[N],t2[N];
int n,len,tot1,tot2;
int a[N];
char c[N];
bool check1(int l1,int r1,int l2,int r2){
	if(r1<l2) return 0;
	if(r2<l1) return 0;
	return 1;
}
bool check2(int l1,int r1,int l2,int r2){
	if(l1<=l2&&r2<=r1) return 1;
	if(l2<=l1&&r1<=r2) return 1;
	return 0;
}
int num(int l1,int r1,int l2,int r2){
	if(!check1(l1,r1,l2,r2)) return 0;
	if(l1<=l2&&r2<=r1) return r2-l2+1;
	if(l2<=l1&&r1<=r2) return r1-l1+1;
	return min(r1,r2)-max(l1,l2)+1;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i],len+=a[i];
	int sum1=0,sum2=0,t=len/2;
	for(int i=1;i<=n;i++){
		if(sum1>=t) break;
		t1[++tot1]={sum1+1,min(sum1+a[i],t),c[i]};
		sum1=min(sum1+a[i],t);
	}
	for(int i=n;i>=1;i--){
		if(sum2>=t) break;
		t2[++tot2]={sum2+1,min(sum2+a[i],t),c[i]};
		sum2=min(sum2+a[i],t);
	}
	int time=1,sum=0;
	for(int i=1;i<=tot1;i++){
		while(time<=tot2){
			int l1=t1[i].l,r1=t1[i].r;
			int l2=t2[time].l,r2=t2[time].r;
			if(t1[i].c!=t2[time].c) sum+=num(l1,r1,l2,r2);
			if(r1>=r2) time++;
			else break;
		}
	}
	cout<<sum;
	return 0;
}