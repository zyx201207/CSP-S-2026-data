#include<bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010],sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	if(n==1){
		cout<<0;
	}
	else{	
		if(sum%2==0){
			cout<<sum/2;
		}
		else{
			cout<<sum/2-1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
