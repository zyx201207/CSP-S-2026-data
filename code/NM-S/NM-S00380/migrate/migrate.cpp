#include<bits/stdc++.h>
using namespace std;
long long x[1000005],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,c,t,i,j;
	cin >> c >> t;
	for(i=1;i<=t;i++){
        cin >> n >> d;
        for(j=1;j<=n;j++){
            cin >> x[j];
        }
        if(x[2]-x[1]>=d){
            cout << 0 << endl;
        }else{
            for(j=1;j<=n;j++){
                if(x[j]>=2*d){
                    cout << n-j+1 << endl;
                    break;
                }
            }
        }
	}
	return 0;
}

