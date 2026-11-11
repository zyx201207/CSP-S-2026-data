#include<bits/stdc++.h>
using namespace std;
int a[10000001],b[10000001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    int w[100010];
    int k[100010];
    int x,y,num;
    cin >> c >> n >> m >> d >> q;
    for(int i=0;i<m;i++){
    	cin >>w[i];
	}
	while(n--){
    	cin >>k[0];
    	num=k[0];
    	for(int i=1;i<1+2*k[0];i++){
            cin >>k[i];
            num+=k[i];
    	}
    	cout <<num << endl;
	}
	while(q--){
    	cin >>x >> y;
	}
    return 0;
}
