#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
        freopen("subway.in","r",stdin);
        freopen("subway.out","w",stdout);
        cin>>c>>t;
        while(t--){
			int n,m;
			cin>>n>>m;
			int a[n];
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			int q=a[1]-a[0];
			if(m<2*q){
				cout<<"0"<<endl;
			}else if(n-1==q){
				cout<<"0"<<endl;
			}else if(m%q==2){
				cout<<"2"<<endl;
			}else if(m%q<=1){
				cout<<"1"<<endl;
			}else{
				cout<<q<<endl;
			}
			
		}
	return 0;
	}

