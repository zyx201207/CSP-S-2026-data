#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],maxn;
bool isA=true,isB=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)isA=false;
		if(i>1&&a[i]-a[i-1]!=a[2]-a[1])isB=false;
	}
	if(isA){
		long long b=(long long)((sqrt(1+8*m)-1)/2);
		cout<<min(n,b+1);
		return 0;
	}else if(isB){
		m/=a[2]-a[1];
		long long b=(long long)((sqrt(1+8*m)-1)/2);
		cout<<min(n,b+1);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>maxn;i--){
		long long num=1,c=m;
		for(int j=i-1;j>0;j--){
			if(a[i]-a[j]<=c)
				c-=a[i]-a[j],num++;
			else break;
		}
		maxn=max(maxn,num);
	}
	cout<<maxn;
	return 0;
}

