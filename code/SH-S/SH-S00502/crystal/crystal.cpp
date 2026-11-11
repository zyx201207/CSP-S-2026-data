#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans,b1,c1,lst,k;
long long a[500005];
struct node{
	long long cnt,id;
}b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]||i==1){
			b1++;
			b[b1].id=a[i];
		}
		b[b1].cnt++;
	}
	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-1);
		if(sum>m){
			ans=max(ans,i-1-lst);
			while(sum>m){
				c1++;
				sum-=(a[i]-b[c1].id)*(b[c1].cnt);
				lst+=b[c1].cnt;
			}
		}
		k=0;
		if(sum<m&&(a[i]-b[c1].id)!=0&&c1>0){
			k=(m-sum)/(a[i]-b[c1].id);
		}
		if(i-lst+k>ans&&c1>0){
			ans=i-lst+k;
		}
	}
	cout<<ans;
	return 0;
}
