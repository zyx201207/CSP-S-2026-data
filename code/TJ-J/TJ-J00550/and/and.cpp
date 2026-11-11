#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m;
cin>>n>>m;
long long a[100000]={};
for(long long i=1;i<=n;i++){
	cin>>a[i];
}
cout<<a[n];
return 0;
fclose(stdin);
fclose(stdout);
}

