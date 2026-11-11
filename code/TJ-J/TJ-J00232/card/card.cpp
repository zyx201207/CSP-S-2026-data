#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int arr[1000000];
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>arr[i];
}
for(int i=0;i<m;i++){
	cout<<n-i;
}

return 0;
} 

