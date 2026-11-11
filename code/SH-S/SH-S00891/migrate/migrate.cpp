#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,i,ans;
ll d,x[2000005],num1[2000005],num2[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(i=1;i<=n;i++){
			cin>>x[i];
			if(i>1)num1[i-1]=x[i]-x[i-1];
			if(i>2)num2[i-2]=num1[i-1]+num1[i-2];
		}
		int l=0,lmax=-1,pos=0;
		for(i=1;i<=n-2;i++){
			if(num2[i]<=d){
				l++;
				if(l>lmax){
					lmax=l;
					pos=i;
				}
			}
			else l=0;
		}
		if(lmax==2){
			int u=1,v=1;
			for(i=pos+1;num1[i]==d;i++)v++;
			for(i=pos-1;num1[i]==d;i--)u++;
			ans+=u*v;
		}
		cout<<ans<<endl;
	}
	return 0;
}
