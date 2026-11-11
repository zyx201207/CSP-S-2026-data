#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],b[200001],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=29;j>=0;j--){
		int sum=0;
		b[0]=0;
		for(int i=1;i<=n;i++)
			if((a[i]>>j)&1){
				sum++;
				b[++b[0]]=a[i];
			}
		if(sum>=m)memcpy(a,b,sizeof a);
	}ans=a[1];
	for(int i=2;i<=m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}
