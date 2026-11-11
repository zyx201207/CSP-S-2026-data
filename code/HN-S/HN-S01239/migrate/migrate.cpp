#include<bits/stdc++.h>
using namespace std;
long long x[2000005],a[2000005]={0};
long long c,t;
long long n,d,gs=1;
bool pd(int a,int b){
	int ans=0;
	if(a+1==b){
		return true;
	}
	for(int i=a;i<=b-1;i++){
		for(int j=i+1;j<=b;j++){
			if(x[j+1]-x[i]<=d){
				if(pd(j,b)) ans++;
			}
			else break; 
		}
	}
	if(ans==2) return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int j=1;j<=n-1;j++){
			if(x[j]+d<x[j+1]){
				for(int qq=j+1;qq<=n;qq++){
					x[qq]=0;
					n--;
				}
				break;
			}
		}
		for(int j=1;j<=n-2;j++){
			for(int mj=j+3;mj<=n;mj++){
				if((mj-j)%2!=0){
					if(j+d<mj){
						if(pd(j,mj)) a[i]++; 
					}
				} 
			}
		}
		cout<<a[i]<<endl;
	}
	return 0;
}
