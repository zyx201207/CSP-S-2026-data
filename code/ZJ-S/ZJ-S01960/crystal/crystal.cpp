#include<bits/stdc++.h>
using namespace std;
long long a[100000010],s[100000010],zd;	
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];		
	}
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
		s[i]=abs(a[i]-a[i-1]);		
    }
	for(long long i=2;i<=n;i++){
		long long b=1,x=0;
		for(long long j=2;j<=n;j++){
			x+=s[j]*b;
			if(x<=m&&(j-i+2)>zd) zd=j-i+2;
			else b++;
		}
	}
	cout<<zd<<"\n";
	return 0;
}
