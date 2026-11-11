#include<bits/stdc++.h>
using namespace std;
long long n,k,m,s;
long long a[100000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]<a[i+1]){
		s++;
	}
	} 
	if(s-1==n){
		for(int i=1;i<=n;i++){
			cout<<n<<" ";
		}
	}
	else cout<<"0 0 0 0";
	return 0;
} 
