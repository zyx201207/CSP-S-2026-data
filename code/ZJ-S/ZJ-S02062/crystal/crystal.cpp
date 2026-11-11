#include<bits/stdc++.h>
using namespace std;
int n,m,z,P,b,sum;
int CL(int a[],int m,int n,int p){
	int l=0;
	int c=1E+5;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			if(p-a[i]<c&&p-a[i]>0){
				c=p-a[i];
				b=i;
			}
		}
		if(c<=m){
			a[b]=p;
			m-=c;
		}
		c=1E+5;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==p){
			sum++;
			l=i;	
		}
	}
	if(m>(sum*(abs(a[l+1])-abs(a[l])))+abs(p)-abs(a[l+1])){
		p=a[l+1];
		CL(a,m,n,p);
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-1;j++){
			if(a[j]>a[j+1]){
				int o;
				o=a[j];
				a[j]=a[j+1];
				a[j+1]=o;
			}
		}
	}
	P=a[n/2+1];
	cout<<CL(a,m,n,P);

	
	
	return 0;
}
