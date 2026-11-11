#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,a,m,,b=2,c=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        if(a[b]>a[c]){
            m=a[b];
            b++;
            c++;
        }
    }
    cout<<m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
