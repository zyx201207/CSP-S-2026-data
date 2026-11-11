#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+5;
struct node{
	int val,idx;
}; 
bool cmp(node x,node y){
	return x.val<y.val;
}
int cost;
node minn;
node a[N];
node diff[N];
int s[N];
int sum=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[0].val;
	a[0].idx=0;
	for(int i=1;i<n;i++){
		cin>>a[i].val;
		a[i].idx=i;
	}
	sort(a,a+n,cmp);
//	minn.val=UINT_MAX;
//	for(int i=0;i<n;i++){
//		cost=0;
//		for(int j=0;j<n;j++){
//			cost+=abs(a[j].val-a[i].val);
//		}
////		cout<<a[i].val<<' '<<cost<<endl ;
//		if(cost<minn.val){
//			minn.val=cost;
//			minn.idx=i;
//		}
//	}
	int id=ceil(1.00000*n/2);
	for(int i=0;i<n;i++){
		if(i==id) diff[i].val=0x3f;
		diff[i].val=abs(a[id].val-a[i].val);
		diff[i].idx=i;	
	} 
	sort(diff,diff+n,cmp);
//	for(int j=0;j<n;j++){
//		cout<<diff[j].val<<' ';	
//	}
//	cout<<"\n\n" ;
	//a[n/2];
	for(int i=1;i<= n;i++){
  		if(m>=diff[i].val){
			m-=diff[i].val;
			a[diff[i].idx].val+=diff[i].val;
			sum++;
		}else break;
	}
	cout<<sum<<endl;
//	for(int j=0;j<n;j++){
//		cout<<a[j].val<<' ';	
//	}
	return 0;
}
/*
5 8
-3 -1 2 2 7


*/
