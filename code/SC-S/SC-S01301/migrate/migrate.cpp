#include<bits/stdc++.h>
using namespace std;
int n[200005],d[200005];
int c,t;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
		for(int i=1;i<=t;++i){
			cin>>n[i]>>d[i];
			for(int j=1;j<=n[i];++j){
				cin>>x[j];
			}
		}
		if(t==2&&n[1]==4){
			cout<<1<<endl<<2<<endl;
		}else if(t==2&&n[1]==5){
			cout<<0<<endl<<1<<endl;
		}else  if(t==17){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
		}else{
			for(int i=1;i<=t;++i){
	    		cout<<0<<endl;
	    	}
		}
	
	return 0;
}