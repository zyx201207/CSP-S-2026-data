//郭溥森 西安辅轮中学 SN-J00639
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m,a[MAXN],b[MAXN];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b[i]=a[i]&a[j];
		}
	}
	sort(b+1,b+1+n,cmp);
	cout<<b[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

