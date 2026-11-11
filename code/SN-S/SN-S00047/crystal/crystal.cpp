#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],s[500005],ans,cnt;
int n,v[5005][5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		v[i][i]=a[i];
		for(int j=i+1;j<=n;j++)
		if(v[i][j-1]<a[j])
		v[i][j]=a[j];
		else
		v[i][j]=v[i][j-1];
	}
	for(long long i=1;i<=n;i++)
		for(long long j=i+1;j<=n;j++){
			cnt=(j-i+1)*v[i][j]-s[j]+s[i-1];	
			if(cnt<=m)
			ans=max(ans,j-i+1);
		}
		cout<<ans;
		return 0;
}
for(int i=1;i<=n;i++){
	cin>>a[i];
}
double x=m/(abs(a[2]-a[1]))*2;
double t=sqrt(x+0.25)-0.5;
int y=t;
cout<<y;
	return 0;
} 
