#include<bits/stdc++.h>
using namespace std;
struct st{
	long long ttot;
	long long stanum;
}k[500][50000];
int main(){
    ifstream cin("subway.in");
    ofstream cout("subway.out");
	//ÊäÈë
    int point,n,m,p,q;
    cin>>point>>n>>m>>p>>q;
    long long rtot[m],lin[n];
    for(int i=0;i<m;i++){
     	cin>>rtot[i];
    }
    for(int i=0;i<n;i++){
    	cin>>lin[i];
    	for(int j=0;j<lin[i];j++){
    		cin>>k[i][j].stanum>>k[i][j].ttot;
		}	
	}
	
	//ÕýÎÄ 
	while(true){
		q--;
		if(q<0)
			break;
		int x,y,timeneed=0;
		cin>>x>>y;
		timeneed+=rtot[x-1];
		timeneed+=rtot[y-1];
		
		cout<<timeneed<<endl;
	}
	
    return 0;
}
