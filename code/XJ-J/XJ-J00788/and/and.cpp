#include<bits/stdc++.h>
using namespace std;
char a[200000][35];
int b[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int c[35];
c[0]=1;
c[1]=2;
for(int i=2;i<=35;i++){
	 c[i]=c[i-1]*2;
}
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int nm;
		cin>>nm;
		int ij=0;
		while(nm>0){
		if(nm%2==0)
			a[i][ij]='0';
		else
		   a[i][ij]='1';
			nm/=2;
			ij++;
		}
		a[i][ij]='0';
		ij++;
		b[i]=ij;
	}
	 
	int maxx=0;
	if(m==2){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int ssum=0;
			for(int ij=0;ij<max(b[i],b[j])-1;ij++){
				ssum+=(a[i][ij]=='1'&&a[j][ij]=='1')*c[ij];
			}
			maxx=max(maxx,ssum);
		}
	}
	}else if(m==1){
		for(int i=0;i<n;i++){
			int ssum=0;
			for(int ij=0;ij<b[i]-1;ij++){
				if(a[i][ij]=='1')
				 ssum+=c[ij];
			}
			maxx=max(maxx,ssum);
	}
	}else if(m==3){
		for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int iij=j+1;iij<n;iij++){
			int ssum=0;
			for(int ij=0;ij<max(b[i],b[j])-1;ij++){
				ssum+=(a[i][ij]=='1'&&a[j][ij]=='1'&&a[iij][ij]=='1')*c[ij];
			}
			maxx=max(maxx,ssum);
		}
		}
	}
	}
	cout<<maxx;
	 return 0;
}