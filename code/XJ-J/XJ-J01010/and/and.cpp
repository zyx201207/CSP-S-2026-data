#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==3){
		a[1] and a[2] and a[3];
		return 0;
	}
	if(m==4){
		a[1] and a[2] and a[3] and a[4];
		return 0;
	}
	if(m==5){
		a[1] and a[2] and a[3] and a[4] and a[5];
		return 0;
	}
	if(m==6){
		a[1] and a[2] and a[3] and a[4] and a[5] and a[6];
		return 0;
	}
	if(m==7){
		a[1] and a[2] and a[3] and a[4] and a[5] and a[6] and a[7];
		return 0;
	}
	if(m==8){
		a[1] and a[2] and a[3] and a[4] and a[5] and a[6] and a[7] and a[8];
		return 0;
	}
	for(int i=1;i<=m-1;i++){
		cout<<a[i] and a[i+1];
	}
	return 0;
}
/*4 2
3 15 12 12*/
