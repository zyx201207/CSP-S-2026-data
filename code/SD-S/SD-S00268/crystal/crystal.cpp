#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,maxn,cnt[210];
long long m,a[500010],ma;
bool A=true,B=true;
const int k=105;
void check(int x){
	if(x==1||x==n)
	    return;
	long long opt=m;
	int l=x-1,r=x+1,ans=1;
	while(opt>=min(a[x]-a[l],a[r]-a[x])){
		if(l>=1&&a[x]-a[l]<=a[r]-a[x]){//×ó±ß±ä´ó 
			opt=opt-(a[x]-a[l]);
			l--;
			ans++;
		}else if(r<=n&&a[x]-a[l]>=a[r]-a[x]){
			opt=opt-(a[r]-a[x]);
			r++;
			ans++;
		}else{
			break;
		}
	}
	if(ans>maxn)
		maxn=ans;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)
		    A=false;
		if(i>=3&&a[i]-a[i-1]!=a[2]-a[1])
		    B=false;
		if(ma<a[i])
		    ma=a[i];
	}
	sort(a+1,a+n+1);
	if(A||B){
		check(n/2);
		check(n/2+1);
		cout<<maxn;
		return 0;
	}else if(n==1){
		cout<<1;
	}else if(n==2){
		if(a[2]-a[1]<=m){
			cout<<2;
		}else{
			cout<<1;
		}
	}else{
		for(int i=1;i<=n;i++)
			check(i);
		cout<<maxn;
	}
	return 0;
} 
