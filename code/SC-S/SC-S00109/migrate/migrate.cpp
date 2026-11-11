#include<bits/stdc++.h>
using namespace std;
int n,a[100010],m,x,y;
long long sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;++i){
		sum=0;
		cin>>x>>y;
		for(int j=1;j<=x;++j){
			cin>>a[j];
		}
		int l=1,r=x;
		while(l<=r){
			if(a[r]*(a[r]+1)>=a[1]){
				sum++;
				r--;
			}else{
				l=r+1;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}