#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0,mx=0,mi,mid;
long long a[500005];
void dg(int sum){
	for(int i=1;i<=n;i++){
		if(abs(a[mid]-a[i])>mx){
			mx=abs(a[mid]-a[i]);
			mi=i;
		}
	}
	
	if(sum<=m){
		return;
	}
	else{
		sum-=mx;
		n--;
		mid=(n+1)/2;
		mx=0;
		dg(sum);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	mid=(n+1)/2;
	for(int i=1;i<=n;i++){		
		sum+=abs(a[mid]-a[i]);
		
	}
	dg(sum);
	
	cout<<n<<endl;

	return 0;
}