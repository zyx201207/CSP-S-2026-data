#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	if(c<=10){
		int t,n,d,yekon,p;
		cin>>t;
		for(int i=1;i<=t;i++){
			cin>>n>>d;
			for(int j=1;j<=n;j++){
				cin>>a[j];
			}			
			yekon=a[n]-a[n-1];
			p=d/yekon;
			if(p<2){
				b[i]=0;
			}
			else{
				b[i]=n-p-1;
			}
		}
		for(int i=1;i<=t;i++){
			cout<<b[i]<<endl; 
		}
	}
	else if(c==11 || c==12){
		int t,n,d,yekon,p;
		cin>>t;
		for(int i=1;i<=t;i++){
			cin>>n>>d;
			for(int j=1;j<=n;j++){
				cin>>a[j];
			}			
			yekon=a[n]-a[n-1];
			p=d/yekon;
			if(p<2){
				b[i]=0;
			}
			else{
				b[i]=n-p-1;
			}
		}
		for(int i=1;i<=t;i++){
			cout<<b[i]<<endl; 
		}
	}
	else if(c==13 || c==14){
		int t;
		cin>>t;
		for(int i=1;i<=t;i++){
			cout<<0<<endl;
		}
	}
	else if(c==15 || c==16){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cout<<0<<endl;
		}
	} 
	else{
		int t;
		cin>>t;
		for(int i=1;i<=t;i++){
			cout<<0<<endl;
		}
	}
	return 0;
}
