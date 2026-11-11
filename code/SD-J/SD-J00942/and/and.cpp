#include<bits/stdc++.h>
using namespace std;  
const int N=5e5+5;

int n,m;
int a[N];
int sum[N][32];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)a[i+n]=a[i];
	n=n*2;
	for(int i=1;i<=n;i++){
		for(int k=0;k<=30;k++){
			sum[i][k]=sum[i-1][k]+((a[i]>>k)&1);
		}
	}
	int num=0;
	for(int i=m;i<=n;i++){
		int ans=0;
		for(int k=0;k<=30;k++){
			if(sum[i][k]-sum[i-m][k]==m){
				ans+=(1<<k);
			}
		}
		num=max(ans,num);
	}
	cout<<num<<'\n';
	return 0;
}//1000000000
