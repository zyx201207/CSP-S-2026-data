#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int t[31];
ll maxx=1;
ll lowbit(int x){return x&(-x);}
int logg2(int x){
	int cnt=0;
	while(x!=0){x/=2;cnt++;}
	return cnt-1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	sort(a+1,a+n+1,[](int x,int y){return x>y;});
	for(int k=1;k<=m;k++) maxx&=a[k];
	cout<<maxx;
	return 0;
}
