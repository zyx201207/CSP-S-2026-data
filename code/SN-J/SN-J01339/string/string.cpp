#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0; 
	cin>>n;
	int a[n+5];
	char b[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		sum+=a[i];
	}
	string many;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			many.push_back(b[i]);
		}
	}
	
	if(sum%2==0){
		int sumsum=sum;
		sum/=2;
		string x,y ;
		for(int i=1;i<=sum;i++){
			x[i]=many[i-1];
		}	
		int wow=1;
		for(int i=sumsum;i>=sum+1;i--){
			y[wow]=many[i-1];
			wow++;
		}	
		long long ans=0;
		for(int i=1;i<=sum;i++){
			if(x[i]!=y[i]){
				ans++;
			}
		} 
			  cout<<ans;
	}else{
		int sumsum=sum;
		sum/=2;
		string x,y ;
		for(int i=1;i<=sum;i++){
			x[i]=many[i-1];
		}	
		int wow=1;
		for(int i=sumsum;i>=sum+2;i--){
			y[wow]=many[i-1];
			wow++;
		}	
		long long ans=0;
		for(int i=1;i<=sum;i++){
			if(x[i]!=y[i]){
				ans++;
			}
		} 
			  cout<<ans;
	}
	
	return 0;
}

