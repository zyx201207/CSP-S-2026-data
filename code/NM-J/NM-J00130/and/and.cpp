#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
long long m,n,k;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(long long i=0;i<n;i++){
	cin>>k;
	a.push_back(k);
}
sort(a.begin(),a.end());
int i=a.size()-1;
long long ans=a[i];
while(m--){
	ans&=a[i];
	i--;
}
cout<<ans;
return 0;
}

