#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[50030],x1[50030],sum;
int qx(int a,int b){
	for(int i=1;i<a-1;i++){
		for(int j=i+2;j<=a;j++){
			if(x1[j]-x1[i]<=b||j-i>=4) continue;
			else{
				sum++;
			}
			
		}
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=50030;j++){
			x[j]=0;
		}
		for(int j=1;j<=n;j++){
			cin>>x[j];
			
		}
		int tol=0;
		for(int j=1;j<=n;j++){
			x1[j]=x[j];
			tol+=1;
			if(x[j+1]-x[j]>d){
				break;
			}
		}
		cout<<qx(tol,d)<<endl;
		sum=0;
	}	
	return 0;
}