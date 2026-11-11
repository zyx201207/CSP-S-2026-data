#include<bits/stdc++.h>
using namespace std;
const int N=2000006;
int c,t,n,d,a[N],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int l=1;l<=t;l++){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		    if(i+d+d-1<=n) cnt++;
	    cout<<cnt<<endl;
	}
	return 0;
}