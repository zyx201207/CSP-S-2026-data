#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
const int N=1e5+10;
long long a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal,out","w",stdout);
	cin>>n>>m;
	bool b=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			b=0;
		}
	}
	int x=1;
	if(b){
		for(int i=1;i<=n;i++){
			if(m>=i){
				m-=a[i];
				x++;
			}
		}
		if(x>=n){
			cout<<n<<endl;
		}
		else{
			cout<<x<<endl;
		}
	}
	else{
		int t=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(m>=t*i){
				m-=t*i;
				x++;
			}
		}
		if(x>=n){
			cout<<n<<endl;
		}
		else{
			cout<<x<<endl;
		}
	}
	return 0;
} 
