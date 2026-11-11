#include<bits/stdc++.h>
using namespace std;
int a[3005][31];
long long n,m,num,maxx;
void ejz(int x,int n){
	long long op=1;
	while(x>0){
		a[n][op]=x%2;
		x/=2;
		op++;
	}
	num=max(num,op);
}
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		ejz(x,i);
		maxx=max(maxx,x);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		int s[31]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},num=0;
		for(int i=1;i<=31;i++){
			for(int j=1;j<=n;j++)s[i]+=a[j][i];
			if(s[i]!=n)s[i]=0;
			else s[i]=1;
		}
		int op=0;
		for(int i=1;i<=31;i++){
			num+=pow(2,op)*s[i];
			op++;
		}
		cout<<num;
	}
	else if(m==n-1){
		int maxx=0;
		for(int x=1;x<=n;x++){
			int s[31]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},num=0;
			for(int i=1;i<=31;i++){
			for(int j=1;j<=n;j++)if(j!=x)s[i]+=a[j][i];
			if(s[i]!=n-1)s[i]=0;
			else if(s[i]==n-1)s[i]=1;
		}
			int op=0;
			for(int i=1;i<=31;i++){
				num+=pow(2,op)*s[i];
				op++;
			}
			maxx=max(num,maxx);
		}
		cout<<maxx;
	}
	else if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			int num=0,s[31]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			for(int j=1;j<=n;j++){
				for(int x=1;x<=31;x++){
					if(a[i][x]&&a[j][x])s[i]=1;
					else s[i]=0;
				}
			}
			int op=0;
			for(int i=1;i<=31;i++){
				num+=pow(2,op)*s[i];
				op++;
			}
			maxx=max(num,maxx);
		}
		cout<<maxx;
	}
	return 0;
}
