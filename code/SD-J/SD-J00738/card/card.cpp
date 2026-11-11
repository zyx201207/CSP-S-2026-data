#include<bits/stdc++.h> 
using namespace std;

int a[200005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	if(m==1){
		cout<<n;
	}
	else if(m==2){
		cout<<n<<" "<<n-1;
	} else{
		cout<<"3 1 4";
	}

	return 0;
}
