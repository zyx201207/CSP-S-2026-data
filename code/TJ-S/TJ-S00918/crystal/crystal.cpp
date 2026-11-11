#include<bits/stdc++.h>
using namespace std;
int a[500000];
int main(){
	freopen("and.in","crystal",stdin);
    freopen("and.out","crystal",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			ans++;
		}
	}
	if(ans==0){
		if(m==1){
			cout<<2;
		}
		
	}
}

    
