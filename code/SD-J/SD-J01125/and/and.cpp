#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+101;
struct node{
	int num,l;
};
node a[N];
int n,m;
int f(int x){
	int p,v=0;
	stack<int> q;
	while(x!=0){
		int p=x%2;
		q.push(p);
		x/=2;
	}
	while(!q.empty()){
		v*=10;
		v+=q.top();
		q.pop();
	}
	return v;
}
int g(int x){
	int cnt=0;
	while(x!=0){
		if(x%10==1)cnt++;
		x/=10;
	}
	return cnt;
}
bool cmp(node u,node v){
	return u.l>v.l;
}
bool tot(node s1,node s2){
	return s1.num>s2.num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i].num=x;
		a[i].l=g(f(x));
	}
	sort(a+1,a+1+n,tot);
	sort(a+1,a+1+n,cmp);
	
	for(int i=2;i<=m;i++){
		a[i].num=((a[i].num)&(a[i-1].num));
	}
	cout<<a[m].num;
	return 0;
}
