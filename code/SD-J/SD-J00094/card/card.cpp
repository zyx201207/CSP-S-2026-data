#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool tp=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2)
			if(a[i]!=a[i-1])
				tp=false;
	}
	if(tp){
		for(int i=1;i<=m;i++){
			if(i==a[1])
				cout<<n<<' ';
			else
				cout<<0<<' ';
		}
	}else{
		sort(a+1,a+n+1);
		int k=1;
		for(int i=1;i<=m;i++){
			if(a[k]==i){
				cout<<n<<' ';
				k++;
			}else{
				cout<<0<<' ';
			}
		}
	}
	cout<<"\n";
	return 0;
}
