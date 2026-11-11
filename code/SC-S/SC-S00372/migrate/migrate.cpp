#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T,p;
bool f=1,t=0;
long long d;
int n,x[N];
void solveA(){
	int k=d/(x[2]-x[1]);
	int sum=2*k;
	if(n<sum){
		cout<<0;
	}else{
		cout<<n-sum+1;
	}
}
bool wn(int x1){
	if(x1-x[1]<=d&&x[n]-x1<=d){
		return true;
	}else{
		return false;
	}
}
void solveB(){
	int k=x[p-1];
	int cnt=p-1+2;
	while(x[cnt]<=k+d){
		cnt++;
	}
	cout<<cnt-p-1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>=3&&x[i]-x[i-1]!=x[i-1]-x[i-2]){
				f=0;
			}
			if(wn(x[i])){
				t=1;
				p=i;	
			}
		}
		if(f==1){
			solveA();
		}
		if(t==1){
			solveB();
		}
	}
	return 0;
}