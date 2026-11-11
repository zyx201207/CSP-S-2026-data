#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int maxx=0;
	for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		int x=(a[j]&a[j+1]);
    		if(x>maxx){
    			maxx=x;
			}
		}
	}
	int y=(a[1]&a[n]);
	if(y>maxx){
		cout<<y;
	}else{
		cout<<maxx;
	}
	return 0;
}
