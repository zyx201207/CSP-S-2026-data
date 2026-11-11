#include<bits/stdc++.h>
using namespace std;
long long sum[3],ans=0;
int n,now[2];
int a[200005],b[200005];
int sa[200005],sb[200005];
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>x;
		b[n-i+1]=a[i];
		sa[i]=int(x)-96;
		sb[n-i+1]=sa[i];
	}
	sum[3]=0;
	while(now[1]<=n&&now[2]<=n){
		
		if(sum[1]<=sum[2]){
			now[1]++;
			sum[1]+=a[now[1]];
			if(sum[1]==sum[2]+b[now[2]+1]){
				now[2]++;
				sum[2]+=b[now[2]];
			}
		}
		else{
			now[2]++;
			sum[2]+=b[now[2]];
			if(sum[2]==sum[1]+a[now[1]+1]){
				now[1]++;
				sum[1]+=a[now[1]];
			}
		}
		if(sa[now[1]]==sb[now[2]]){
		}
		else{
			ans=ans+min(sum[1],sum[2])-sum[3];
		}
		sum[3]=min(sum[1],sum[2]);
	}
	cout<<(ans+1)/2;
	return 0;
}