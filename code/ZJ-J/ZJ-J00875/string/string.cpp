#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cnt,mid,sxt,ans,a[200005],l[200005],r[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	mid=(cnt+1)/2;
	for(int i=1;i<=n;i++){
		if(!sxt)l[i]=r[i-1]+1,r[i]=l[i]+a[i]-1;
		if(sxt)l[i]=r[i-1]+1,r[i]=l[i]+a[i-1]-1,c[i]=c[i-1];
		if(cnt%2==0){
			if(l[i]==mid&&r[i]==mid)continue;
			if(l[i]<=mid&&r[i]>=mid){
			    n++;
			    sxt=i+1;
			    r[i+1]=r[i],l[i+1]=mid+1,r[i]=mid;
			    i++;
		    }
		    continue;
		}
		if(l[i]<mid&&r[i]>mid){
			n++;
			sxt=i+1;
			r[i+1]=r[i];
			l[i+1]=mid+1;
			r[i]=mid-1;
			//cout<<l[i]<<" "<<r[i]<<" "<<l[i+1]<<" "<<r[i+1]<<" ";
			i++;
			continue;
		}
		if(l[i]==mid){l[i]++;continue;}
		if(r[i]==mid)r[i]--;
	}
	if(sxt){
		c[sxt]=c[sxt-1];
	}
	ans=cnt/2;
	for(int i=1;i<=n;i++){
		if(r[i]>mid)break;
		ll L=cnt-r[i]+1,R=cnt-l[i]+1;
		ll x=lower_bound(l+1,l+n+1,L)-l;
		ll y=lower_bound(l+1,l+n+1,R)-l;
		for(int j=x+1;j<y;j++){
			if(c[j]==c[i])ans-=r[j]-l[j]+1;
		}
		if(x==y&&c[x]==c[i]){
			ans-=R-L+1;
			continue;
		}
		if(c[x]==c[i])ans-=r[x]-L+1;
		if(c[y]==c[i])ans-=R-l[y]+1;
	}
	cout<<ans;
	return 0;
}/*
4
2 a
1 b
1 a
1 c
*/
