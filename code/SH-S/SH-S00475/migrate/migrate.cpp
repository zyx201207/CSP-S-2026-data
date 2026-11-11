#include<bits/stdc++.h>
using namespace std;
int t,n,dis,d,a[2000010],dist[200010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	while(t--){
		bool f=1;
		int sum=0;
		cin>>n>>dis;
		cin>>a[1]>>a[2];
		d=a[2]-a[1];
		for(int i=3;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=d)f=0;
		}
		if(f){
		    if(dis>=n/2*d){
			    sum++;
	            dis-=(n/2*d);
		        sum+=dis/(d*2);
		        cout<<sum<<'\n';
		    }
		    else cout<<0<<'\n';
	    }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
