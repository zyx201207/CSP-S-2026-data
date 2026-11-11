#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],block;
char c[N];
long long sum[N],b[26],l,r,ans;
void get(long long l,long long r){
	memset(b,0,sizeof b);
	for(long long i=l;i<=r;i++){
		if(sum[block]>=r){
			b[c[block]-'a']+=r-i+1;
			break;
		}
		b[c[block]-'a']+=sum[block]-i+1,i=sum[block],block++;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i],sum[i]=sum[i-1]+a[i];
    if(sum[n]%2==1){
    	int x;
    	long long mid=sum[n]/2+1;
    	for(int i=1;i<=n;i++)
    	   if(sum[i]>=mid){
    	   	   x=i;
    	   	   break;
		   }
		block=x;
		l=mid+1;
		for(int i=x;i>=1;i--){
			if(mid==sum[x-1]+1&&i==x){
				continue;
			}
			long long sze;
			if(i==x)sze=mid-sum[x-1]-1;
			else sze=sum[i]-sum[i-1];
			if(i==x)get(l,l+sze-1),l=l+sze;
			else get(l,l+sze-1),l=l+sze;
			long long res=0;
			for(int j=0;j<26;j++)
			   if(j!=c[i]-'a')res+=b[j];
			ans+=res;
		}
		cout<<ans;
	}else{
		int X;
    	long long mid=sum[n]/2;
    	for(int i=1;i<=n;i++)
    	   if(sum[i]>=mid){
    	   	   X=i;
    	   	   break;
		   }
		block=X;
		l=mid+1;
		for(int i=X;i>=1;i--){
			long long sze;
			if(i==X)sze=mid-sum[X-1];
			else sze=sum[i]-sum[i-1];
			if(i==X)get(l,l+sze-1),l=l+sze;
			else get(l,l+sze-1),l=l+sze;
			long long res=0;
			for(int j=0;j<26;j++)
			   if(j!=c[i]-'a')res+=b[j];
			ans+=res;
		}
		cout<<ans;
	}
	return 0;
}