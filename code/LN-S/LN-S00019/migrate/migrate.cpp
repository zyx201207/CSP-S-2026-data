#include<bits/stdc++.h>
using namespace std;
const int R = 200010;
int a[R],n,m;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,o;
    cin>>c>>o;
    for(int oo = 1;oo <= o;oo++){
        int sum = 0;
        cin>>n>>m;
        for(int i = 1;i <= n;i++){
            cin>>a[i];
        }
        int l = int(m/(a[2]-a[1]));
        sum = int(((n-l+1)/l));
        if(2*m > n)cout<<0;
        else cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
