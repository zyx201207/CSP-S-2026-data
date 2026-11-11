#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[300025];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--){
		int tans=ans|(1<<i);
		int num=0;
		for(int i=1;i<=n;i++){
			if((a[i]&tans)==tans) num++;
		}if(num>=k) ans|=(1<<i);
	}cout<<ans;
	return 0;
} 
