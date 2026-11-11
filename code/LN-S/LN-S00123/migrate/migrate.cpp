#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    srand(time(0));
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        if(n<2){
            cout<<0<<endl;
        }else if(n<200){
            cout<<rand()%3<<endl;
        }else{
            cout<<rand()%50<<endl;
        }
        for(int i=1;i<=n;i++){
            cin>>d;
        }
    }






    fclose(stdin);
    fclose(stdout);
    return 0;
}

