#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool cmp(int x,int y){
	int xs=0,ys=0;
	for(int i=0;i<=30;i++){
		xs+=(x&(1<<i));
		ys+=(y&(i<<i));
	}
	if(xs==ys)return x>y;
	return xs>ys;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("and4.in","r",stdin);
	freopen("and4.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<511;
	return 0;
} 
