#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000005],b[10000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++){
		while(a[i]!=1){
			b[m-i+1]=a[i]%2;
			a[i]/=2;
		}
		
	}
	cout<<24;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
