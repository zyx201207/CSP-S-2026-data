#include<bits/stdc++.h>
using namespace std;
const int N=2e3+66;
long long c,t,x[N],dx[N];
	long long n,d;
int jl(int q,int z,int num,vector<int>a){
if(q==z) return num;
num++;
int l=q,r=z,an=q;
while(l<=r){
int mid=(l+r)/2;
if(x[mid]-x[q]>d) r=mid-1;
else{
an=mid;
l=mid+1;
}
}
return jl(an,z,num,a);
}
int xz(int jl,int q,int z,int num){
if(q>=z && num<=jl) return 1;
if(num>=jl) return 0;
long long ans=0;
for(int i=q+1;i<=z&&x[i]-x[q]<=d;i++){
ans+=xz(jl,i,z,num+1);
}
return ans;
}
int  main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
	scanf("%lld %lld",&n,&d);
	bool f=0; 
	for(int i=1;i<=n;i++){
	scanf("%lld",&x[i]);
	if(i!=1 && i!=2 && x[i]-x[i-1]!=x[i-1]-x[i-2]) f=1;
	}
	if(f==0){
	int cha=x[2]-x[1];
	if(cha>d){printf("0"); continue;}
	int bu=cha/d;
	long long ans=0;
	for(int i=0;i<n && cha*(n-i)>d;i++){
	for(int j=n-1;j>=i+1;j--)
	if((((j-i)*cha)%d)!=0&&(j-i-1)==2)
	ans++;
	}
	printf("%lld\n",ans);
	continue;
	}
	vector<int>p[N];
	long long o=1;
	for(int i=1;i<=n;i++){
	if(x[i]-x[i-1]>d){
	if(x[i+1]-x[i]<=d){
	if(i==1) p[o].push_back(i);
	else p[++o].push_back(i);	
	}
	}
	else p[o].push_back(i);
	}
	long long ans=0;
	for(int i=1;i<=o;i++){
	for(int j=0;j<p[o].size();j++){
	int v=p[o][j];
	for(int k=v+1;k<p[o].size();k++){
	int u=p[o][k];
	int zx=jl(v,u,0,p[o]);
	cout<<v<<" "<<u<<' '<<zx<<'\n';	
	int pp=xz(zx,v,u,0);
	if(pp==2) ans++;
	cout<<pp<<'\n';
	}
	}
	}
	printf("%lld\n",ans);
	}
	return 0;
} 
