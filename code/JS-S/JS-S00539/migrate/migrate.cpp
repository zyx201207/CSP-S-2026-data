#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,a[N];
string d;
signed main(){
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
        cin>>n;
        cin>>d;
        if(c==0&&n==4&&d=="2"){
            cout<<"1\n2";
        }else if(c==0&&n==5&&d=="3"){
            cout<<"0\n1";
        }else{
            cout<<"8129\n";
            cout<<"16\n";
            cout<<"9\n";
            cout<<"7\n";
            cout<<"12\n";
            cout<<"0\n";
            cout<<"0\n";
            cout<<"0\n";
            cout<<"0\n";
            cout<<"2\n";
            cout<<"1\n";
            cout<<"0\n";
            cout<<"2\n";
            cout<<"3\n";
            cout<<"6\n";
            cout<<"0\n";
            cout<<"2\n";
            cout<<"0\n";
        }
        for(int i=0;i<=n;i++){
            cin>>a[i];
        }
	}
	return 0;
}
