#include<bits/stdc++.h>
using namespace std;
int g[200009];
char c[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i]>>c[i];
	}
	int s=0,t=0;
	int j=n;
	long long ans=0;
	for(int i=1;i<=j;i++){
		while(s<g[i]&&i<=j){
			if(c[i]!=c[j]){
			    ans+=(long long)min(g[i]-s,g[j]-t);
		    }
		    int u=min(g[i]-s,g[j]-t);
		    s+=u;
		    t+=u;
		    if(t==g[j]){
		    	j--;
		    	t=0;
			}
		}
		s=0;
	}
	cout<<ans;
	return 0;
}
