#include<bits/stdc++.h>
using namespace std;
int n,m,s[200010][31],mx,f[2010][2010];
struct node{
	int x,b[31];
}a[200010];
void er(int x,int y){
	int i=1;
	while(y>0){
		a[x].b[i]=y%2;
		y/=2;
	}
	return;
}
bool cmp(node x,node y){
	return x.x>y.x;
}
void dfs(int level,int st,int num){
	if(f[level][st]>num)return;
	else f[level][st]=num;
	if(level==m){
		mx=max(mx,num);
	}
	for(int i=st+1;i<=n;i++){
		dfs(level+1,i,num&a[i].x);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		er(i,a[i].x);
		for(int j=1;j<=30;j++){
			if(!a[i].b[j])s[i][j]=s[i-1][j]+1;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1].x;
		return 0;
	}
	else if(m==2){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ma=max(ma,a[i].x&a[j].x);
			}
		}
		cout<<ma;
		return 0;
	}
	else if(m==n){
		int sum=0;
		for(int i=1;i<=30;i++){
			if(s[n][i]==0)sum+=pow(2,i);
		}
		cout<<sum;
		return 0;
	}
	if(m==n-1){	
		int ma=0,f=0;
		for(int i=1;i<=n;i++){
			int k[31];
			for(int j=1;j<=30;j++){
				k[j]=s[n][j];
			}
			int fl=0;
			for(int j=1;j<=30;j++){
				if(k[j]==1&&a[i].b[j]==0){
					k[j]=0;
					fl=1;
					f=1;
				}
			}
			if(fl==1){
				int sum=0;
				for(int i=1;i<=30;i++){
					if(s[n][i]==0)sum+=pow(2,i);
				}
				ma=max(ma,sum);				
			}			
		}	
		if(f)cout<<ma;
		else{
			int sum=0;
			for(int i=1;i<=30;i++){
				if(s[n][i]==0)sum+=pow(2,i);
			}
			cout<<sum;
		}
		return 0;		
	}
	dfs(0,0,1073741823);
	cout<<mx;
	return 0;
}