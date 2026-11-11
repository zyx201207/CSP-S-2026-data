#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int cnt=a[1];
	if(m==1){
		cnt=cnt&0;	
	}else if(m==n){
		for(int i=2;i<=m;i++){
			cnt=cnt&a[i];
		}
	}else{
		for(int i=2;i<=m;i++){
			cnt=cnt&a[i];
		}
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
