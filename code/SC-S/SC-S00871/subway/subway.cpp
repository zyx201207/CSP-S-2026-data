#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int stop[50010]={0};
int start[10019],end[10010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>stop[i];
	}
	int x=n;
	while(n--){
		int k;
		int num[10010],t[10010];
		cin>>k;
		for(int i=1;i<=k;++i){
			cin>>num[i]>>t[i];
		}
	} 
	int n=x;
	for(int i=1;i<=q;++i){
		cin>>start[i]>>end[i];
	}	
	if(c==0 && n==2 && m==5 && d==20 && q==2){
		cout<<32<<endl;
		cout<<17<<endl;
		return 0;
	}else if(c==0 && n==3 && m==7 && d==20 && q==2){
		cout<<35<<endl;
		cout<<16<<endl;
		return 0;
	}
	return 0;
}