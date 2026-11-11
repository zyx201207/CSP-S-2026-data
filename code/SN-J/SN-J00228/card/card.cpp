#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500005];
int num[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
    	cin>>a[i];
    	num[i] = -1;
	}
	for(int i = n,j = 0;i >= 1,j <= i;i--,j++){
		num[a[i]] = max(num[a[i]],n-j);
	}
	if(m == 1){
		cout<<n; 
	}else{	
		for(int i = 1;i <= m;i++){
			if(num[i]!=-1){
				cout<<num[i]<<" ";
			}	
	   }
	}
	
}
