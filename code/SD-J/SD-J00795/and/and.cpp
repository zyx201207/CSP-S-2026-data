#include<bits/stdc++.h>
using namespace std;
long long n,m,b[100005];
bool cmp(int x,int y){
	return x>y;
}
long long cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>b[i];
	}
	if(n==m){
		cnt=b[1];
		for(int i=2;i<=n;i++){
			cnt=cnt&b[i];
		}
		cout<<cnt;
		return 0;
	}
	if(m==1){
		long long ma=-2e9;
		for(int i=1;i<=n;i++){
			ma=max(ma,b[i]);
		}
		cout<<ma;
		return 0;
	}
	sort(b+1,b+1+n,cmp);
	cnt=b[1];
	for(int i=2;i<=m;i++){
		cnt=cnt&b[i];
	}
	cout<<cnt<<endl;
	return 0;
}
