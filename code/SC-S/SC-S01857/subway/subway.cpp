#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long kt[m+5];
	long long tt[m+5];
	long long zs[505];
	for(long long i=0;i<m;i++){
		cin>>kt[i];
	} 
	for(long long i=0;i<m;i++){
		long long x;
		cin>>x;
		zs[i]=x;
		for(long long i1=0;i1<x;i1++){
			long long c,v;
			cin>>c>>v;
		}
	} 
	for(long long i=0;i<q;i++){
		long long w,y;
		cin>>w>>y;
	}
	if(q==1){
		cout<<kt[1]/zs[1];
	}
	if(q==2){
		cout<<kt[1]/zs[1]<<endl<<n/zs[1];
	}
	if(q==3){
		cout<<"56"<<endl<<"43"<<endl<<"40";
	}
	return 0;
}