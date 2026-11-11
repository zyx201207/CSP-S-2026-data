#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],t,tt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)
			t+=1;
		else
			tt+=1;
	}
	if(tt==1&&a[n]==2){
		cout<<n<<" "<<n*(n-1)/2;
	}
	else if(tt==1&&a[n]==2){
		cout<<n*(n-1)/2<<" "<<n;
	}
	else{
		if(a[n]==2){
			cout<<0<<" "<<n;
		}
		else{
			cout<<n<<" "<<0;
		}
	}
	return 0;
}
