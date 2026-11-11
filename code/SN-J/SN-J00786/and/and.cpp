//杜吕俊泽 SN-J00786 西安辅轮中学 
#include<bits/stdc++.h>
#define int long long  
using namespace std;
int n,m,p;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	p=(a[1] & a[2]);
	for(int i=3;i<=m;i++){
		p&=a[i];
	}
	cout<<p;
	return 0;
}

