#include<bits/stdc++.h>
using namespace std;
const int N=601000;
int n,a[N],m,b[N],d[N],p[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int h=n,e=1;
	while(h--){
		for(int i=e;i<=n;i++){
		    b[i]=a[i];
		    for(int j=1;j<=i-1;j++){
			    if(b[i]==b[j]){
			    	for(int k=i-1;k>=j;k--){
			    		b[k]=-1;
					}
			    }
		    }
	    }
	    for(int j=1;j<=n;j++){
	    	for(int k=1;k<=m;k++){
				if(b[j]==k){
					p[k]++;
				}
			}
		}
	    memset(b,-1,sizeof(b));
	    e++;
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}
	return 0; 
}
