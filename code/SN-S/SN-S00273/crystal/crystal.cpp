#include<bits/stdc++.h>

using namespace std;
int T=1;
long long n,m,a[500008],b[500008],anss=1;
int main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n-1;i++){
			b[i+1]=a[i+1]-a[i];
			//cout<<a[i]<<" ";
		}
		for(int i=2;i<=n;i++){
			long long s=m,ss=0,ans=1;
			for(int ii=i;ii>=2;ii--){
			ss+=b[ii];
			s-=ss;
			//cout<<s<<" ";
			if(s<0)break;
			ans++;
			}
			anss=max(ans,anss);
		}
		cout<<anss<<endl;
	}
	return 0;
}
