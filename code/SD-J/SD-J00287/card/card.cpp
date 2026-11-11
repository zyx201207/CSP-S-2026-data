#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j=1;
    while(j<=n){
    	bool f=1;
    	string b;
    	for(int x=j;x<=n;x++){
    		for(int y=0;y<=b.size()-1;y++){
    			if(b[y]==a[x]){
    				f=0;
    				break;
				}
			}
			if(f){
				b.erase(x,b.size());
				b+=a[x];
			}
			else{
				b+=a[x];
			}
	    }
		for(int z=0;z<=b.size()-1;z++){
			int sum=(int)b[z];
			ans[sum]++;
		}
		j++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
