#include<bits/stdc++.h>
using namespace std;
#define N 500005
int n,m,sum,sum1;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]==1) sum++;
		else sum1++;
	}
	if(sum==sum1){
		cout<< n/2<<" "<<n;
	}
	if(sum!=sum1){
		if(sum>sum1){
			cout<<n<<" "<<n/2;
		}
		else{
			cout<<n/2+1<<" "<<n;
		}
	}
	return 0;
}
