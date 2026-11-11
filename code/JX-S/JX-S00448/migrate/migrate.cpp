#include<iostream>
#include<cstdio>
using namespace std;
int c,n,t,d,a[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        int num=a[2]-a[1];
        int sum=d/num;
        cout << n-sum-1 << endl;
    }




    return 0;
}

