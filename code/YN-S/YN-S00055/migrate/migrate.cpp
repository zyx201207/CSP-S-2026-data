#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000002];
signed main()
{
    freopen("migrate.in","r",stdin);
 freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];

        }
        if(d==1){
            cout<<"0\n";
        }else if(d%(x[2]-x[1])==0){
     //   cout<<"114514";
    if(x[1]+d+(d-(x[2]-x[1]))>x[n]){
        cout<<"0\n";
    }else{
for(int i=1;i<=n;i++){
    if(x[1]+d+(d-(x[2]-x[1]))==x[i]){
        cout<<n-i+1<<"\n";
     i=n+1;
    }
}

    }
   }else{
             //  cout<<"114514";
 //  d=d-(d%(x[2]-x[1]));
   if(x[1]+d+(d-(x[2]-x[1]))>x[n]){
    cout<<"0\n";
   }else{
       for(int i=1;i<=n;i++){
    if(x[1]+d+(d-(x[2]-x[1]))==x[i]){
        cout<<n-i+1<<"\n";
        i=n+1;
    }
   }
   }


    }
    }
    //cout << "Hello world!" << endl;
    return 0;

}
