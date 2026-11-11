#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int c,t,f[N];
int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k,num=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)f[i]=i;
		if((n-1)/2>=k){
			for(int i=1;i<=(n-1)/2;i++){
				int u,v;
				cin>>u>>v;
				int fu=find(u),fv=find(v);
				if(fu==fv)continue;
				f[fu]=fv;
				num++;
			}if(num>=f[i])cout<<1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

