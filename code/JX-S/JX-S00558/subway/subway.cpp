#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,mmm,nn,l,n2,m2,x22,y22,choi,k1=9999999999999999;
vector<long long>mm;
vector<long long>x;
vector<long long>y;
vector<long long>v;
vector<long long>x2;
vector<long long>y2;
vector<long long>bo;
vector<long long>key;
vector<long long>kk;
int main(){
	freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=0;i<m;i++){
		cin>>mmm;
		mm.push_back(mmm);
	}
	l=m;
	for(long long i=0;i<n;i++){
		cin>>nn;
		l+=1;
		for(long long j=0;j<nn;j++)
		{
			cin>>n2>>m2;
			x.push_back(n2);
			y.push_back(l);
			v.push_back(m2);
			x.push_back(l);
			y.push_back(n2);
			v.push_back(m2);
		}	
	}
	for(long long i=0;i<q;i++){
		cin>>x22>>y22;
		x2.push_back(x22);
		y2.push_back(y22);
		
	}
	for(long long i=0;i<q;i++){
		bo.clear();
		key.clear();
		for(long long j=0;j<l+3;j++){
		    bo.push_back(1);
		    key.push_back(99999999999);}
		x22=x2[i];
		y22=y2[i];
		key[x22-1]=0;
		choi=x22;
		while(choi!=y22){
			cout<<key[y22-1]<<endl
			k1=99999999999999;
			for(long long j=0;j<x.size()-1;j++){
				if(x[j]==choi) key[y[j]-1]=min(key[y[j]-1],key[x[j]-1]+v[j]);
				//cout<<key[y22-1]<<endl;
				
			}
			
			bo[choi-1]=0;
			for(long long j=0;j<bo.size();j++)
			{
				if(bo[j]==1&&key[j]<k1){
					k1=key[j];
					choi=j+1;
									
				}
			}}	
		cout<<key[y22-1]+mm[x22-1]+mm[y22-1]<<endl;
}
	}
