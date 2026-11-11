
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t){
    	int n,k,u[10005],v[10005],ans[10005]={0},r=0;
    	cin>>n>>k;
    	for(int i=1;i<n;i++){
    		cin>>u[i]>>v[i];
    		ans[v[i]-u[i]]++;
    	}
    		for(int i=1;i<n;i++){
    			if(ans[i]>=k){
    				r=i;
    				break;
				}
			}
		cout<<r;
    	t--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
