#include<bits/stdc++.h>
using namespace std;
long long n,m;
int s[200010][1000];
long long a[200010];
bool v[200010];
long long c[200010];
long long maxn=INT_MIN;
void jz(int x){
	long long num=a[x];
	long long len=0;
	while(num){
		s[x][++len]=num%2;
		num/=2;
	}
	maxn=max(maxn,len);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		jz(i);
	}
	for(int i=1;i<=maxn;i++){
		for(int j=1;j<=n;j++)
			if(s[j][i]==1)
				c[i]++;
	}
	for(int i=maxn;i>=1;i--){
		if(c[i]>=m){
			for(int j=1;j<=n;j++)
				if(s[j][i]==0&&v[j]==0){
					v[j]=1;
					for(int k=1;k<=maxn;k++)
						if(s[j][k]==1)c[k]--;
				}
		}
	}
	long long ans=0,sum;
	for(int i=1;i<=n;i++)
		if(v[i]==0){
			sum=a[i];
			break;
		}
	for(int i=1;i<=n;i++){
		if(ans==m)break;
		if(v[i]==0){
			ans++;
			sum=sum&a[i];
		}
	}
	cout<<sum;
	return 0;
}