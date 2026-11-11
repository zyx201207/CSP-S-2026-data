#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout)
long long a[10000005];
int m,n;
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>a[i];

}
sort(a,a+n);
int sum=0;
for(int i=0;i<n;i++){
	if(a[i]>m){
		sum++;
	}
}
cout<<sum;
    return 0;
}
