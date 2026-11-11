#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int x[505];
pair<int,int> a[505],t[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>x[i];
		cin>>a[i].first>>t[i].first>>a[i].second>>t[i].second;
	}
	int b[q],e[q],ti[q];
	for(int i=0;i<q;i++){
		cin>>b[i]>>e[i];
		ti[i]=0;
	}
	for(int i=0;i<q;i++){
		ti[i]+=w[b[i]]+w[e[i]];
		int wz=b[i],lll=0;
		while(1){
			for(int j=0;j<n;j++){
				if(a[j].first==wz){
					ti[i]+=t[j].first+t[j].second;
					wz=a[j].second;
				}
				if(wz==e[i]){
					lll=1;
					break;
				}
			}
			if(lll==1){
				break;
			}
		}
		
	}
	for(int i=0;i<q;i++){
		cout<<ti[i]<<endl;
	}
	return 0;
} 
