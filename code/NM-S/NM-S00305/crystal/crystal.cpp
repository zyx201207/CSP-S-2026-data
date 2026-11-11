#include<bits/stdc++.h>
using namespace std;
freopen("crystal.in","r",stdin);
freopen("crystal.out","w"stdout);
long long n,m,k,sum,MAX;
long long a[510000];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int x=1;
		sum=1;
		k=m;
		while(a[i-k]+k>=a[i]&&i-x>=1){
			sum++;
			k=k-(a[i]+a[k-i]);
			x++;
		}
		MAX=max(MAX,sum);
    }
    cout<<MAX;
    return 0;
}