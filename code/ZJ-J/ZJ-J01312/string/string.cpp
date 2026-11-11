#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long n,k[MAXN],sum,u,v,ans,zd=0;
char c[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i]>>c[i];
		sum+=k[i];
		zd=max(zd,k[i]);
	}
	if(zd<=50){
		string q="";
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k[i];j++)q+=c[i];
		long long len=q.size();
		q=" "+q;
		for(int i=1;i<=len/2;i++)
			if(q[i]!=q[len+1-i])ans++;
		cout<<ans;
		return 0;
	}
	long long s=0;
	for(int i=1;i<=n;i++){
		s+=k[i];
		if(s==sum/2+1 and sum%2==1 and k[i]==1)break;
		if(s==sum/2 and sum%2==0)break;
		if(s>sum/2){
			if(sum%2==1){
				for(int j=n;j>=i+1;j--){
					k[j+2]=k[j];
					c[j+2]=c[j];
				}n+=2;
				long long t=0;
				for(int j=n;j>=i+3;j--)t+=k[j];
				k[i+2]=sum/2-t;
				k[i+1]=1;
				k[i]=k[i]-k[i-1]-k[i-2];
			}else{
				for(int j=n;j>=i+1;j--){
					k[j+1]=k[j];
					c[j+1]=c[j];
				}n++;
				k[i+1]=s-sum/2;
				k[i]=k[i]-k[i+1];
			}
			c[i+1]=c[i];
			break;
		}
	}
	long long l=1,r=n;
	char ls;
	long long gs=0;
	bool f=0;
	while(l<r){
		if(u+k[l]<=sum/2)u+=k[l];
		if(f)if(ls!=c[l])ans+=gs;
		gs=f=0;
		while(v<u){
			v+=k[r];
			if(v>u){
				ls=c[r];
				gs=v-u;
				if(c[r]!=c[l])ans+=u-(v-k[r]);
				f=1;
			}else if(c[r]!=c[l])ans+=k[r];
			r--;
		}
		l++;
	}
	cout<<ans;
	return 0;
}