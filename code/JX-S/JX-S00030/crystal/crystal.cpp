#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long d[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    //cout<<n<<" "<<m<<endl;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);

    d[0] = 0;

    for(int i = 1;i<n;i++){
        d[i] = ((a[i] - a[i-1]) * i) + d[i-1];
    }

    int fid = n-1;
    while(d[fid]>m){
        fid--;
    }

    cout << fid+1 <<endl;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
