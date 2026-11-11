#include<bits/stdc++.h>
using namespace std;
long long d[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t;
    cin >>c>>t;
    long long n,m;
    while(t--){
    	cin >>n>>m;
    	bool o=0,p=0;
    	for(int i=1;i<=n;i++){
    		cin >>a[i];
		}
		for(int i=3;i<=n;i++){
    		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
    			o=1;
			}
			else{
				p=a[i]-a[i-1];
			}
		}
		if(o==0){
		    int y=(m/p);
		    if(y==1||y==0){
		    	cout <<0;
		    	continue;
			}
			else{
				cout <<1;
			}
		}
	}
	return 0;
} 