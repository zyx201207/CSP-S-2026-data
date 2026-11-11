#include<bits/stdc++.h>
using namespace std;
int main(){
freopen ("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
long long n,m,c[500005],ans=INT_MIN;
cin>>n>>m;
for(int i=0;i<=n+1;i++){
	c[i]=INT_MAX;
}
for(int i=1;i<=n;i++){
	cin>>c[i];
}
sort(c+1,c+n+1);
for(int i=1;i<=n;i++){
	long long num=1,m1=m;
	for(int j=1;j<i;j++){
		m1-=c[i]-c[i-j];
		if(m1<0){
			break;
		}
		else{
			num++;
		}
	}
	ans=max(ans,num);
}
cout<<ans;
return 0;
}
