#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200050],s,q,x,y;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x1=0,x2=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x=n;
	y=n;
	if(m==2){
		if(a[n]==1){
			for(int i=n-1;i>=1;i--){
				if(a[i]==2){
					cout<<n<<" "<<i<<endl;
				}
			}			
		}else{
			for(int i=n-1;i>=1;i--){
				if(a[i]==1){
					cout<<i<<" "<<n<<endl;
				}
			}			
		}

	}
	else{
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
	}
	return 0;
}

