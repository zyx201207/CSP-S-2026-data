#include<bits/stdc++.h>
#define int long long
using namespace std;
const int L=2e5+10;
int n,m,a[L];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

cin>>n>>m;
int x1=-1,x2=1;
for(int i=1;i<=n;i++){
	cin>>a[i];
	x1=max(a[i],x1);
	x2&=a[i];
	
}

if(m==1){
	cout<<x1;
}
else{
	cout<<x2;
}
	return 0;
}
