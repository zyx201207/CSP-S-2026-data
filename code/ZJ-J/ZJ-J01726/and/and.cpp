#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int t;
int cnt;
bool cmp2(int x,int y){
	return x>y;
}
bool cmp(int x,int y){
	return (x&t)>(y&t);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp2);
	t=a[0];
	cnt=t;
	sort(a,a+n,cmp);
//	for(int i=0;i<m;i++){
//		cout<<a[i]<<endl;
//	}
	for(int i=1;i<m;i++){
		cnt=(cnt&a[i]);
	}
	cout<<cnt;
	return 0;
}
