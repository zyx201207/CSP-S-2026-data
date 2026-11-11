#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt;
	cin>>n>>m;
	int a[n+5],b[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]==0){
			cnt++;
			b[a[i]]++;
		}
	}
	 for(int i=1;i<=cnt;i++){
	 	cout<<a[b[i]];
	 }  
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
