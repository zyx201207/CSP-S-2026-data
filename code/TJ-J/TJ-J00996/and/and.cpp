#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    	int  n,m,sum=-1,ans=0;
    	cin>>n>>m;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans=a[i]&a[j];	
				if(sum<ans){
					sum=ans;
				}
			}
		}
	cout<<ans;
return 0;
}

