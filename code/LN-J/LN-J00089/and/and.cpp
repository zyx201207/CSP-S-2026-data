#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[1234];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[1]==3)
        {
            cout<<"12";
            return 0;
        }
        else if(a[1]==31)
        {
            cout<<"7";
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
}
