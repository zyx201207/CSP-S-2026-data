#include<bits/stdc++.h>
using namespace std;

long long v,n,u,add,ans,a[500005];
bool e;
vector<int> p;

struct date{
	int s[300005];
}game[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(long long i=1;i<=n;i++){
        for(int j=i-1-v;j<n;j++){
        	for(int q=i-1;q<j;q++){
        		if(p[q+1]==a[j]){
        			e=1,add=q;
        			break; 
				}
			}
			if(e){
				for(u=j;u>add;u--){
					game[i].s[u]=0;
				}
				e=0,v+=u;
			}
			game[i].s[v]=a[j];
			v++;	
       	}
       	v=0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i+1;j++){
			if(game[i].s[j]==i){
				ans++;
				continue;
			}
		} 
	}
	
    cout<<ans;
	return 0;
}
