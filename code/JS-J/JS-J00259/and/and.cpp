#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	int p=a[1]&a[2];
	if(m==2){
		cout<<p;
		return 0;
	}
	for(int i=3;i<=m;i++){
		p=p&a[i];
	}
	cout<<p;
	return 0;
}
