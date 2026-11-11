#include<bits/stdc++.h>
#define LANH using
#define AK namespace
#define CSPS std
LANH AK CSPS;
typedef long long ll;
int n;
ll d,a[2000009];
vector<ll>sd;
ll s[2000009];
void Main(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
//	if(n>=5000){
//		puts("0");
//		return ;
//	}
//	for(int i=1;i<=n;i++){
//		int x=i;
//		for(int j=i+1;j<=n;j++){
//			if(a[i]+d<a[j])break;
//			x=j;
//		}
//		cout<<x<<' ';
//	}
//	puts(""); 
	ll sum=0,xx=0,yy=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)s[j]=0;
		sd.clear();
		bool f=0,dd=0;
		int sl=0;
		sd.push_back(a[i]);
		for(int j=i+1;j<=n;j++){
			sl=j;
			if(sd.back()+d<a[j])sd.push_back(a[j-1]);
			if(sd.back()+d<a[j])break;
			//
			int x=lower_bound(a+1,a+1+n,a[j]-d)-a;
			int y=lower_bound(a+1,a+1+n,sd.back())-a;
			f=s[y]&1;
			if(s[y]==2)break;
		//	cout<<sd.back()<<'\n';
			if(x+1==y&&x>=i){
				if(f){
					f=0;
					s[j]=2;
					continue;
				}
				f=1;
				int z=lower_bound(a+1,a+1+n,a[x]-d)-a;
				int yy=lower_bound(a+1,a+1+n,*(--(--sd.end())))-a;
				if(z>=i&&z<yy){
					s[j]=2;
					continue;
				}
			}else if(x<y&&x>=i){	
				s[j]=2;
				continue;
			}
			if(f&&!dd){
				dd=1;
				xx=j;
			}
			s[j]=f;
			sum+=f;
		//	cout<<i<<' '<<j<<'\n';
		}
	//	assert(sl>=yy);
	//	yy=lower_bound(a+1,a+1+n,sd.back())-a;
	//	if(!sd.empty())xx=lower_bound(a+1,a+1+n,*(--lower_bound(sd.begin(),sd.end(),xx)))-a;
	//	xx=max(xx,i*1ll);
	}
	cout<<sum<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)Main();
	return 0;
}

