#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n];
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long num=(m+a[2]-a[1])/2;
    long long sum=0;
    a[1]=a[1]+=num;
    a[2]=a[2]+m-num;
    for(int i=1;i<=n;i++){
		if(a[i]==a[3]){
			sum++;
		}
	}
	cout<<sum;
    return 0;
}
