#include <bits/stdc++.h>
using namespace std;
struct sum{
	long long b;
	int a[32];
}q[200050];
int boo[200050],yboo[200050],boor=0,num,n,m,maxn=0;
long long x,sum[32],cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sum[0]=1;
	for(int i=1;i<=30;i++)sum[i]=sum[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		num=0;
		while(x>0){
			q[i].a[num]=x%2;
			num++;
			x/=2;}
			maxn=max(num,maxn);} 	
	for(int j=maxn;j>=0;j--){
		boor=0;
		for(int i=1;i<=n;i++){
		    if(!(q[i].a[j]==1&&yboo[i]==0)){
		    	boor++;
		    	boo[boor]=i;
			}
	    }
	    if(boor<=(n-m)){
	    	for(int i=1;i<=boor;i++)yboo[boo[i]]=1;
	    	cnt+=sum[j];
		}
	}
	cout<<cnt;
	return 0;
}
