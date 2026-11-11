#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=0,k=0,now=0,xx=0,yy=0,p=1,q=1,s=0;
char c;
struct node{
	ll e;
	char c;
};
node a[200010];
node d[200010];
ll b[200010];
char ch[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		cin>>ch[i];
		k+=b[i];
	}
	for(int i=1;i<=n;i++){
		now=min(now+b[i],k/2);
		a[i].e=now;
		a[i].c=ch[i];
		//cout<<a[i].e<<" "<<a[i].c<<endl;
		xx++;
		if(now>=k/2)break;
	}
	now=k;
	for(int i=n;i>0;i--){
		now=max(now-b[i],k/2);
		d[n-i+1].e=k-now;
		d[n-i+1].c=ch[i];
		//cout<<d[n-i+1].e<<" "<<d[n-i+1].c<<endl;
		yy++;
		if(now<=k/2)break;
	}
	while(p<=xx && q<=yy){
		//cout<<p<<" "<<q<<endl;
		if(a[p].e==d[q].e){
			if(a[p].c != d[q].c){
				ans+=a[p].e-s;
			}
			s=a[p].e;
			p++;
			q++;
		}else if(a[p].e>d[q].e){
			if(a[p].c != d[q].c){
				ans+=d[q].e-s;
			}
			s=d[q].e;
			q++;
		}else{
			if(a[p].c != d[q].c){
				ans+=a[p].e-s;
			}
			s=a[p].e;
			p++;
		}
	}
	cout<<ans;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
