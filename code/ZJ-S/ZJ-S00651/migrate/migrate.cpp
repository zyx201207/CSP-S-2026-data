#include<bits/stdc++.h>
using namespace std;
int c;
int q;
int a[100001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>q;
    while(q--){
    	int n,d;
    	cin>>n>>d;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
		}
		bool flag=true;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				flag=false;
				break;
			}
		}
		if(flag){
			int gc=a[2]-a[1];
			int xx=d/gc;
			if(n%2==1){
				cout<<n/(xx*2)+1<<endl;
			}
			else{
				cout<<n/(xx*2)<<endl;
			}
		}
	}
	return 0;
}
