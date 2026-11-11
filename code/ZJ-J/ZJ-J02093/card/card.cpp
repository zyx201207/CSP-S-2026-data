#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],pj[500005],cnt;
int ck(int sz){
	for(int i=1;i<cnt;i++){
		if(pj[i]==sz)return i;
	}return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		cnt=1;
		for(int j=i;j<=n;j++){
			int s=ck(a[j]);
			if(s==0){
				pj[cnt++]=a[j];
			}
			else{
				cnt=s;
				pj[cnt++]=a[j];
			}
		}
		for(int j=1;j<cnt;j++){
			b[pj[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",b[i]);
	}
}