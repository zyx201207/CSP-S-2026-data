#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
long long n,d,sum=0;
int cmp(int l,int r){
	int x=0;
	for(int i=l;i<r;i++){
		if(abs(a[i]-a[i+1])>d)return -1;
	}
	int i=l;
	while(i<r){
		int q=d;
		while(q>=0){
			q-=a[i+1]-a[i];
			i++;
		}
		i--;
		x++;
	}
	return x;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int X,T;
	cin>>X>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		cout<<n-3<<endl;
	}
	return 0;
}