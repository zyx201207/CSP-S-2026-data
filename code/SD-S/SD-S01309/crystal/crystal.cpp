#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	bool flagA=1;
	bool flagB=1;
	cin>>n>>m;

	int d1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			d1=a[i]-a[i-1];
		}
		if(a[i]!=i){
			flagA=0;
		}
		if(i>1&&a[i]-a[i-1]!=d1){
			flagB=0;
		}
	}
	
	if(flagA==1){
		int k=1;
		int sum=0;
		while(sum+k<=m){
			sum+=k;
			k++;
		}
		if(k<n){
			cout<<k;
			return 0;
		}
		else{
			cout<<n;
			return 0;
		}
	}

	int d2=d1;
	d1=abs(d1);
	if(flagB){
		int k=1;
		int s=d1;
		int sum=0;
		while(sum+k<=m){
			sum+=s;
			k++;
			s+=d1;
		}
		if(k<n){
			cout<<k;
			return 0;
		}
		else{
			cout<<n;
			return 0;
		}
	}
	
	sort(a+1,a+n+1);
	int b[100005];
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			b[i]=0;
			continue;	
		}
		b[i]=a[i]-a[1];
	}
	cout<<endl;
	int c=0,j=0;
	while(c+b[j+1]<=m){
		c+=b[j+1];
		j++;
	}
	cout<<j;
	return 0;
} 
