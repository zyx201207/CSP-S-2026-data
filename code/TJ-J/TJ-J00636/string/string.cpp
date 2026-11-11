#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k[10005],ans;
	cin>>n;
	int l[2][n];
	for(int i=0;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>l[j][i];
		}
	} 
	for(int i=0;i<=n-1;i++){
		for(int j=1;j<=l[1][n];j++){
			k[i+j]=l[2][i];
		}
	}
	if(n%2==0){
		for(int i=1;i<=n/2;i++){
			if(k[i]==k[n-i]){
				ans=ans+0;
			}
			else{
				ans+=1;
			}
		}
	}
	else{
		for(int i=1;i<=n/2-1;i++){
			if(k[i]==k[n-i]){
				ans=ans+0;
			}
			else{
				ans+=1;
			}
		}	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
