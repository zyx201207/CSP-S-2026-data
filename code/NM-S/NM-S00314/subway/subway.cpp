#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f[1000005],g[1000005],nm[1000005],sg[1000005],qd[1000005],zd[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>a>>b>>c>>d>>e;
	for(int i=0;i<c;i++){
        cin>>f[i];
	}
	for(int i=0;i<b;i++){
            cin>>nm[b];
        for(int j=0;j<nm[b];j++){
            cin>>g[j];
            cin>>sg[j];
        }
	}
	for(int i=0;i<e;i++){
        cin>>qd[i]>>zd[i];
	}
	for(int i=0;i<e;i++){
	    int zs=0;
        for(int j=qd[i]-1;j<zd[i];j++){
            zs+=sg[j];
        }
        cout<<f[qd[i]]+zs+f[zd[i]];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
