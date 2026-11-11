#include<bits/stdc++.h>
using namespace std;
int n,m;

struct node{
	long long a;
	bool id[50];
};
node s[200100];
long long p[50];
int cmp(node x,node y){
	if(x.a >y.a )return 1;
	return 0;
}
int res[30];
long long ma=-1;
int cc[30];
void dfs(int now,int time){
	if(now==n+1){
		if(time!=m)return;
		long long ans;
		int f=0;
		for(int i=1;i<=n;i++){
			if(res[i]){
				if(f==0){
					ans=s[i].a ;
					f=1;
				}
				else ans&=s[i].a ;
			}
		}
		ma=max(ma,ans);
		return ;
	}
	res[now]=1;
	dfs(now+1,time+1);
	res[now]=0;
	dfs(now+1,time);
}
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=35;i++){
		p[i]=p[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i].a ;
		long long na=s[i].a ;
		for(int j=31;j>=0;j--){
			if(p[j]<=na){
				s[i].id [j]=1;
				na-=p[j];
			}
		}
	}
	sort(s+1,s+1+n,cmp);
	if(n<=20){//n<=20:No 1~5
		memset(res,0,sizeof(res));
		dfs(1,0);
		cout<<ma;
	}
	else if(m==1){//No 6
		cout<<s[1].a ;
	}
	else if(m==n){//No 7
		long long aa=s[1].a ;
		for(int i=2;i<=n;i++){
			aa&=s[i].a ;
		}
		cout<<aa;
	}
	else if(m==2){//No 8~10;
		long long aa=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				aa=max(aa,s[i].a &s[j].a );
			}
		}
		cout<<aa;
	}
	else if(m==n-1){//No 11~12;
		memset(cc,0,sizeof(cc));
		for(int i=1;i<=n;i++){
			for(int j=0;j<=31;j++){
				cc[j]+=s[i].id [j];
			}
		}
		long long aa=-1;
		for(int i=1;i<=n;i++){
			long long tt=0;
			for(int j=0;j<=31;j++){
				cc[j]-=s[i].id [j];
			}
			for(int j=0;j<=31;j++){
				if(cc[j]==n-1&&cc[j]!=0){
					tt+=p[j];
				}
			}
			aa=max(aa,tt);
		}
		cout<<aa;
	}
	else{
		int f1=0,f2=0;
		for(int i=1;i<=n;i++){
			for(int j=31;j>=0;j--){
				if(s[i].a ==p[j]-1){
					f1++;
					break;
				}
			}
			if(s[i].a <4){
				f2++;
			}
		}
		if(f1==n){//No 13;
			long long aa=s[1].a ;
			for(int i=2;i<=m;i++){
				aa&=s[i].a ;
			}
			cout<<aa;
		}
		else if(f2==n){//No 16 17
			int ss0=0,ss1=0,ss2=0,ss3=0;
			for(int i=1;i<=n;i++){
				if(s[i].a ==0)ss0++;
				if(s[i].a ==1)ss1++;
				if(s[i].a ==2)ss2++;
				if(s[i].a ==3)ss3++;
			}
			if(ss3>=m)cout<<"3";
			else if(ss3<m){
				if(ss2>=m)cout<<"2";
				else if(ss2<m){
					if(ss1>=m-ss3)cout<<"1";
					else cout<<"0";
				}
			}
		}
	}
	return 0;
}

