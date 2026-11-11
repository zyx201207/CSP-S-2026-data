#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
	}else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}else{
		cout<<1;
	}
	return 0;
}

