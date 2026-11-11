#include<bits/stdc++.h>
using namespace std;
long long int a[500001],n;
bool check(int k){
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=k){
			return 1;
		}
	}
	return 0;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int p=0,da=0,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(check(a[2]-a[1])==1){
		for(int i=2;i<=n;i++){
		long long int t=0,g=0,c=0;
		for(int j=i-1;j>=1;j--){//找到一个数 在这个数和1的区间 找到和它最小差值的数 
		    t=t+(a[i]-a[j]);
		    g++;
			if(t>m){
				break;
			} 
			if(t==m){
				g=g+1;
				break;
			}
		}
		if(da<g){
			da=g;
		}
		}
		cout<<da;
	}else{
		long long int d=a[2]-a[1];
		long long int t=0,l=1;
		for(int i=1;i<=n;i++){
			t=t+i-1;
			l=d*t;
			if(l>m){
				cout<<i-1;
				break;
			}
			if(l==m){
				cout<<i;
				cout<<'=';
				break;
			}
		}
	}
	
	return 0;
} 