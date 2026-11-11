#include<bits/stdc++.h>
using namespace std;
long long a[1000005];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int cnt=0;
        int n;
        long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        for(int i=1;i<=n;i++){
            for(int j=n;j>i;j--){
                    int s=a[j]-a[i];
                if(s%d==1&&s/d==1&&j-i==3){
                    cnt++;

                }
            }

        }
   cout<<cnt<<endl;
}

 return 0;
}

