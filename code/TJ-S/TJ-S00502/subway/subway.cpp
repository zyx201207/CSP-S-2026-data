#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];//time
struct T{
    int num,ti,road;
}t[500010];
struct Q{
    int beg,ed;
}qq[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
    	int x;
    	cin>>x;
    	for(int j=0;j<x;j++){
    		cin>>t[i].num>>t[i].ti;
			t[i].road=j;	
		}
	}
	for(int i=0;i<q;i++){
		cin>>qq[i].beg>>qq[i].ed;
	}
    

    return 0;
}


