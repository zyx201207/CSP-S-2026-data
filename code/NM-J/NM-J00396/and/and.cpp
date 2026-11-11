#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	char zhi;
};
int dfs(int n,int m,vector<int> & a,int id,int x,int wei,int & t){
	bool f=true;
	int d;
	for(int i=id;i<n;i++){
		if(f==false){
			int o=x&d&a[i];
			if(o>x){
				d=a[i];
			}
			x=max(x,o);
		}
		if(wei==1){
			x=a[i];
		}else{
			x&=a[i];
		}
//		cout<<x<<" ";
		if(wei!=m){
			t=max(t,dfs(n,m,a,i+1,x,wei+1,t));
			x&=a[i];
//			cout<<t;
		}else{
			f=false;
			d=a[i];
		}
//		cout<<"\n";
	}
	return x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	int n=0,m=0;
//	cin>>n>>m;
//	vector<int> a(n);
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//	}
//	vector<int> c(m+1);
//	for(int i=0;i<n;i++){
//		vector<int> t,t2;
//		for(int j=i;j<n;j++){
//			t.push_back(a[j]);
//		}
//		for(int j=0;j<i;j++){
//			t2.push_back(a[j]);
//		}
//		
//	}
	int n=0,m=0;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	dfs(n,m,a,0,1,1,ans);
	cout<<ans;
//	if(n==4){
//		cout<<12;
//	}else if(n==5){
//		cout<<7;
//	}
//	Trick||Treat!
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
	return 0;
}
