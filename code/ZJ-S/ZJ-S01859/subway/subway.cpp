#include<bits/stdc++.h>
using namespace std;
struct node{
	int k,a[200005];
	long long t[200005];
}e[505];
int c,n,m,d,q,w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>e[i].k;
		for(int j=1;j<=e[i].k;j++){
			cin>>e[i].a[j]>>e[i].t[j];
		}
	}
	for(int p=1;p<=q;p++){
		long long time=0;
		long long x,y,flag1=0,flag2=0,flag3=0,t=0;
		cin>>x>>y;
		time+=w[x];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=e[i].k;j++){
				if(e[i].a[j]==x){
					time+=e[i].t[j];
					flag3=i;
				}
			}
		}
		for(int j=1;j<=e[flag3].k;j++){
			if(e[flag3].a[j]==y){
				time+=e[flag3].t[j]+w[y];
				t=1;
				cout<<time<<endl;
				continue;
			}
		}
		flag3=0;
		if(t==0){
			for(int i=1;i<=n;i++){
				for(int k=1;k<=m;k++){
					for(int j=1;j<=n;j++){
						for(int l=1;l<=m;l++){	
							if(e[i].a[k]==e[j].a[l]){
								flag1=e[i].t[k];
								flag2=e[j].t[l];
								flag3=j;
								break;
							}
						}	
					}break;		
				}			
			}
			time+=flag1+flag2+e[flag3].t[y]+w[y];
			cout<<time+1<<endl;				
		}
		t=0;
	}
	return 0;
}
