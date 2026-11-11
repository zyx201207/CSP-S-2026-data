#include<bits/stdc++.h>
using namespace std;
long long n,nm[500007],m,ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nm[i];
	}sort(nm+1,nm+n+1);
	long long qd=1;
	for(int i=2;i<=n;i++){
		long long v=nm[i-1],u=nm[i];

		if((i-qd)*(u-v)<=m){
			ans=max(i-qd+1,ans);
			m-=(i-qd)*(u-v);
		}else{
			while((i-qd)*(u-v)>m){
				if(qd>=i)break;
				m+=(v-nm[qd]);
				qd++;
			}
			ans=max(i-qd,ans);
			m-=(i-qd)*(u-v);
			if(qd>i)qd=i;
		}
	}cout<<ans<<endl;
	return 0;
}

