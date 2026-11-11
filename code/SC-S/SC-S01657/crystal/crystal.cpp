#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long b[500010]={0};

void dp(int f,long long ma){
	if(f==n)  cout<<ma;
	int c[500010];
	int z=0;
	z=f+1;
	int mm=m;
	long long num=0;
	for(int i=1;i<=n;i++) c[i]=b[i];
	for(int i=n;i>=1;i--){
		mm=m;
		while(c[i]<=z && mm!=0){
			if(c[i]<z){
				c[i]++;
				mm--;
			}else if(c[i]==z){
				num++;
				break;
			}
		}
	}
	if(ma>num-1){
		 dp(z,ma);
	}else{
		 dp(z,num);
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>b[i];
	
	dp(0,-1);

	return 0;
}
