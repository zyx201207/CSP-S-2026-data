#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct f{
	int l,a;
	char b;
	bool w;
}c[600005],d[600005];
int pre[600005],nxt[600005];
//map<int,int>mp1,mp2
f pp[600005];
int n;
bool cmp(f x,f y){
	return x.l<y.l;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].a>>c[i].b;
		pre[i]=pre[i-1]+c[i].a;
		pp[i]={pre[i]-c[i].a+1,c[i].a,c[i].b,true};
	}
	int len=pre[n];
	for(int i=n;i>=1;i--){
		nxt[i]=nxt[i+1]+c[i].a;
		pp[i+n]={nxt[i]-c[i].a+1,c[i].a,c[i].b,false};
	}
	pp[n+n+1]={pre[n]+1,0,'\0',true};
	sort(pp+1,pp+2+n+n,cmp);
	int lst=1,ans=0;
	char c1='\0',c2='\0';
	for(int i=1;i<=(2*n+1);i++){
//		cout<<pp[i].l<<" "<<pp[i].a<<" "<<pp[i].b<<" "<<pp[i].w<<endl;
		if(c1!=c2)ans+=pp[i].l-1-lst+1;
		if(pp[i].w==true){
			c1=pp[i].b;			
		}else{
			c2=pp[i].b;
		}
//		cout<<c1<<" "<<c2<<" "<<endl;
		
		lst=pp[i].l;
	
//		cout<<"-"<<ans<<endl;
	}
	cout<<(ans+1)/2<<endl;
}
