#include<bits/stdc++.h>
using namespace std;
int n,m,a[10086];
int cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		if(a[i]==a[i+1]){
				cnt++;
				continue;
		}
		
		cout<<cnt-1;
		return 0;
	}
	
	
	return 0;
}
