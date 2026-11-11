#include<iostream> 

using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	
	cin>>n>>m;
	
	int b[100000]={0};
	int a[600000]={0};
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	
	for(int i=1;i<n;i++){
		if(i==1){
			cout<<n-i;
		}else if(i>1&&n-1>i){
			cout<<"1";
		}else if(i==n-1){
			cout<<n;
		}
	}
	
	return 0;
}
