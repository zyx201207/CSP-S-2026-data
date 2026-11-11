#include<iostream>

using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	
	cin>>n>>m;
	
	long long a[1000000];
	
	long long maxx=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i] and a[j] > maxx){
				maxx = a[i] and a[j];
			}
		}
	}
	cout<<maxx;
	return 0;
}
