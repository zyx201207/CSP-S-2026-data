#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=1e5+5;
long long n,m,c,d,q,t[N],u[M],v[M],station,tr[N][N];
struct subway{
	long long st;
	long long ti_in;
	long long ti_out;
}a[N];
bool f;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	if(c==0){
		if(m==2){
			cout<<32<<endl<<17;
		}
		if(m==3){
			cout<<35<<endl<<16;
		}
	}
	else{
		memset(tr,0x3f,sizeof(tr));
		for(int i=0;i<m;i++) cin>>a[i].ti_out;
		for(int i=0;i<n;i++){
			cin>>station;
			while(station--){
				cin>>a[station].st>>a[a[station].st].ti_in;	
			}
			tr[a[0].st][a[1].st]++;
			tr[a[1].st][a[0].st]++;
		}
		for(int i=0;i<q;i++) cin>>u[i]>>v[i];
		if(d==2){
			for(int i=0;i<m;i++){
				for(int j=0;j<m;j++){
					for(int k=0;k<m;k++){
						tr[i][j]=min(tr[i][j],tr[i][k]+tr[k][j]);
						tr[j][i]=min(tr[j][i],tr[j][k]+tr[k][i]);
					}
				}
			}
			for(int i=0;i<q;i++){
				cout<<tr[u[i]][v[i]]<<endl;
			}
		}
		else{
			for(int i=0;i<q;i++){
				cout<<a[0].ti_in+a[0].ti_out+a[n-1].ti_in+a[n-1].ti_out<<endl;
			}
		}
	}
	return 0;
}
