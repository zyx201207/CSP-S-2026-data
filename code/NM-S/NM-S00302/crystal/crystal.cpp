#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[500500],_max=-0x3f3f3f,sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int x=1;
		sum=1;
		k=m;
		while(a[i-x]+k>=a[i] && i-x>=1){
				sum++;
				k=k-(a[i]-a[i-x]);
				x++;
		} 
		_max=max(_max,sum);
	}
	cout<<_max;
	return 0;
}