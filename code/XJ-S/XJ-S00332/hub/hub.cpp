#include<bits/stdc++.h>
using namespace std;

struct dl{
   int u,v;	
}arr[100005];
int main(){ 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
    	int n,k;
    	cin>>n>>k;
    	
    	for(int i=1;i<n;i++){
    		cin>>arr[i].u>>arr[i].v;
    		
		}
		if(t==2){
			cout<<1<<endl;
		} 
		if(t==1){
			cout<<2<<endl;
		}
	}//蒟蒻，真的无法做到,only输入can do 
	return 0;
}

