#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[100005];
	cin>>n;
	int pai=0;
	while(n){
		for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]) return 0;
		else int a[i]++;
		}
	}
	cout >> a[i];	
	return 0;
}  
