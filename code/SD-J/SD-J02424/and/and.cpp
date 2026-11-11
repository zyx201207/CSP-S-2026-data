#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005][35],s[200005];
long long dy=1024*1024*1024-1;
int dfs(int x,int y){
	if(x>n){
		if(y==m){
			return dy;
		}
		else{
			return 0;
		}
	}
	int c=dfs(x+1,y);
	long long dx=dy;
	dy=(dy&a[x]);
	int d=dfs(x+1,y+1);
	dy=dx;
	return max(c,d);
}
void cc(int ij,int nn){
	
	int cnt=0;
	for(int i=1;i<=nn;i++){
		int x=a[i],cn=0; 
		while(x>0){
			b[i][++cn]=x/2;
			x%=2; 
		}
	}
	for(int i=ij;i>=1;i--){
		for(int j=1;j<=nn;j++){
			if(b[j][i]==1){
				s[++cnt]=a[j];
			}
			if(i==1){
				int as=s[1];
				for(int k=2;k<=cnt;k++){
					as=(as&s[k]);
				}
				cout<<as;
				exit(0);
			}
			if(cnt>m){
				for(int k=1;k<=nn;k++){
					a[k]=s[k];
				}
				cc(i-1,cnt);
			}
			else if(cnt==m){
				int as=s[1];
				for(int j=2;j<=cnt;j++){
					as=(as&s[j]);
				}
				cout<<as;
			}
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}

	if(m==1){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2&&n<=2000){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		int ms=a[1];
		for(int i=2;i<=n;i++){
			ms=(ms&a[i]);
		}
		cout<<ms;
		return 0;
	}
	if(n<20){
		cout<<dfs(1,0);
		return 0;
	}
	

	cc(30,n);
	
	
	
	return 0;
} 
/*
4 2
3 15 12 12

*/
