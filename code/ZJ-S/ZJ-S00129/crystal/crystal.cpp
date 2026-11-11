#include<bits/stdc++.h>
using namespace std;

	long long n,m;
	long long a[500005];
	long long f[100000][100000];
	long long t[100000][100000];
	long long r[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=a[j]-a[i];
			//cout<<f[i][j];
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]<0){
				t[i][j]=0;
			}
			else{
				t[i][j]=f[i][j];
			}
		}
	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			r[i]+=t[j][i];
			
		}
		//cout<<r[i];
	}
	
long long b=0;
	for(int i=1;i<=n;i++){
		if(r[i]==m){
			for(int k=1;k<=n;k++){
				if(f[k][i]>0||f[k][i]==0){
					b++;
		
				}
			
			}
			cout<<b;
			break;
		}
		
		if(r[i]>m){
			for(int k=1;k<=n;k++){
				if(f[k][i-2]>0||f[k][i-2]==0){
					b++;
			
				}

		}
		cout<<b;	
		break;
	}
}
	
	
	
	
	
	return 0;
}
