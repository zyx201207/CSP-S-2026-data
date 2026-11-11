#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000015],zs;
struct ll{
	int id,time,last[1000015];
}a[100015];
int main(){
	cin>>c;
	if(c==0){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);		
	}
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int o;
		cin>>o;
		int qm=0;
		for(int j=1;j<=o;j++){
			int name,t;
			cin>>name>>t;
			a[name].time+=t;
			a[name].id=name;
			if(j==1){
				a[name].last[i]=0;				
			}
			a[name].last[i]=qm;
			qm=name;
		}
	}
	for(int i=1;i<=q;i++){
		int strat,end;
		cin>>strat>>end;
		zs+=w[strat]+w[end];
		int qq=end;
		while(1){
			if(a[qq].id==strat){
				break;
			}
			zs+=a[qq].time;
			int sf=1;
			while(1){
				if(a[qq].last[sf]!=0){
					break;
				}
			}
			qq=a[a[qq].last[sf]].id;
		}
		cout<<zs<<endl;
	}
	return 0;
}
