#include<bits/stdc++.h>
using namespace std;
int n,m,k=pow(2,31)-1;
int a[350000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(false);

cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	}
sort(a+1,a+n+1,greater<int>());
if(a[1]==a[2]&&m==2){
	cout<<a[1];
	return 0;
	}
for(int i=1;i<=m;i++){
	k&=a[i];
	}
	cout<<k;
cin.tie(nullptr);
cout.tie(nullptr);
return 0;
}
