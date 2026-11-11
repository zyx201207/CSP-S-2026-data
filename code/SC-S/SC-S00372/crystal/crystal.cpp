#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
bool f=1,t=1;
long long m,a[N];
void solveA(){
	int k=1,s=0;
	while(s<=m){
		s+=k;
		k++;
	}
	cout<<k-1;
}
void solveB(){
	int s=a[2]-a[1],sum=0,k=1;
	while(sum<=m){
		sum+=k*s;
		k++;
	}
	cout<<k-1;
}
void solvesmall(){
	int sum=0,k=1;
	for(int i=1;i<=n;i++){
		sum=0;
		k=1;
		for(int j=i-1;j>=1;j--){
			int c=a[i]-a[j];
			if(sum+c<=m){
				sum+=c;
				k++;
			}else{
				break;
			}
		}
		ans=max(ans,k);
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=0;
		}
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3){
			t=0;
		}
	}
	sort(a+1,a+n+1);
	if(f==1){
		solveA();
		return 0;
	}
	if(t==1){
		solveB();
		return 0;
	}
	solvesmall();
	return 0;
}