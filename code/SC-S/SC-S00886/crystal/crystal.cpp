#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k=2,sum;
int q[N],h[N];
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	sort(q+1,q+n+1);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			h[i]=q[i]-q[j]+h[i];
			if(h[i]==m)sum=max(sum,i);
			if(j+1==i)h[i]=0;
		}
		 
	}
	printf("%d",sum);
	
	return 0;
}