#include<bits/stdc++.h>
using namespace std;
struct aa{
	int zhan[60000065];
	int t[60000086];
	int a[60000086];
};
struct a2{
	int b[60000086];
	int e[60000086];
};
int w[10000086]
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	aa che;
	for(int i=1;i<=n;i++){
		cin>>che.zhan[i];
		for(int j=1;j<=che.zhan[i];j++){
			cin>>che.a[j]>>che.t[j];
		}
	}
	a2 jihua;
	for(int i=1;i<=p;i++){
		cin>>jihua.b[i]>>jihua.e[i];
	}
	
	return 0;
}

