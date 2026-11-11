#include<bits/stdc++.h>
using namespace std;
int n,ans,p1,p2,f;
short vis[500010];
long long a[500010],b[500010],m,an;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i]; 
		an+=a[i];
	}
	an/=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==an){
			p2=i-1;
			p1=i/2;
			f=p1+1;
		}
		else if(a[i]>an){
			ans+=i-p2;
		}
	}
	cout<<an<<" "<<p1<<" "<<p2;
	
	f=f/2;
	while(!(vis[p1]==-1&&vis[p1+1]==1)&&p1!=0){
		if((b[p2]-b[p1-1]+m)/n>=an){
			vis[p1]=1;
			p1-=f;
		}
		else{
			vis[p1]=-1;
			p1+=f;
		}
		f/=2+1;
	}
	ans+=p2-p1;
	cout<<ans;
	
	return 0;
}
