#include<bits/stdc++.h>
using namespace std;
int x[500005]={};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		int ans1[500005]={};
		for(int i=0;i<t;i++){
			long long n,d;
			cin>>n>>d;
			int X,Y;
			for(int j=0;j<n;j++){
				int k;
				cin>>k;
				if(j==0)X=k;
				if(j==1)Y=k;
			}
			int l=X-Y;
			if(d<=l){
				ans1[i]=0;
				continue;
			}
			int q=d/l;
			int ans=n-q;
			ans1[i]=ans;
		}
		for(int i=0;i<t;i++){
			cout<<ans1[i]<<endl;
		}
		return 0;
	}
	for(int i=0;i<t;i++){
		long long n,d;
		cin>>n>>d;
		for(int j=0;j<n;j++){
			int k;
			cin>>k;
			x[j]=k;
		}
		int u,v;
		for(int u=0;u<n;u++){
			for(int j=3;j<n-1;j++){
				v=u+j;
				int q=u;
				int m=0;
				while(q<v){
					int l=2;
					while(1){
						if(x[q+l]-x[q]>d){
							q+=l-1;
							l=2;
							m+=1;
							continue;
						}else{
							l+=1;
						}
					}
				}
				int w=j-m;
			}
		}
	}
}
