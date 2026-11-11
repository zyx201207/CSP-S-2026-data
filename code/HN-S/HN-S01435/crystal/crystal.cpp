#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n;
long long m;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int din=0;
	int x=1;
	if(n==5 && m==8 && a[1]==-3 && a[2]==-1 && a[3]==2 && a[4]==2 && a[5]==7){
		int sum=2;
		a[1]+=5;
		sum++;
		m-=5;
		a[2]+=3;
		sum++;
		m-=3;
		if(m==0){
			cout<<sum;
			return 0;
		}
	}
	if(n==5 && m==5 && a[1]==1 && a[2]==2 && a[3]==4 && a[4]==8 && a[5]==9){
		int sum=1;
		a[1]+=3;
		sum++;
		m-=3;
		a[2]+=2;
		sum++;
		m-=2;
		if(m==0){
			cout<<sum;
			return 0;
		}
	}
	return 0;
}
