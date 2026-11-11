#include<bits/stdc++.h>
using namespace std;
int n,m,a[10086];
int ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
        cout<<a[i]<<endl;
        break;
    }

    }


freopen("and.in","r","in");
freopen("and.out","w","out");
 return 0;
}
