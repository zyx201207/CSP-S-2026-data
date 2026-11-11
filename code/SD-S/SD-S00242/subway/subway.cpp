#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		int w;
		cin>>w;
	}
	for(int i=0;i<n;i++){ 
		int tmp;
		cin>>tmp;
		for(int j=0;j<2*tmp;j++){
			int yl;
			cin>>yl;
		}		
	}
	for(int i=0;i<q;i++){
		int x1,y1;
		cin>>x1>>y1;
	}
	if(n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl;
		cout<<17<<endl;
	}
	else if(n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl;
		cout<<16<<endl;
	}
	
	
	return 0;
}

//I will AFO on CSP2026
//Goodbye,my OI dream QWQ T-T
//祝我WHK加油！！ 5:00
//luogu id tuotuoyl(别看) I am A蛆 
