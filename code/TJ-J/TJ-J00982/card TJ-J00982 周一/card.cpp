#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[1000002];
	string s;
	int n,m,ans;
	cin>>n>>m;
	while(n)
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i];
		for(int j=0;j<n;j++){
			if(a[i]==s[j]){
				while(j){
					s[j]=0;
				}
				continue;
			}	
		}
		for(int k=0;k<n;k++){
			if(a[i]==k){
				ans+=1;
			}
		}
		cout<<ans;
		ans=0;
	}
	
	return 0;
}
