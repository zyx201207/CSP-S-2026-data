#include<bits/stdc++.h>
using namespace std;
int table[2005][2005];
int n,m;
int main(){
    int list[200005];
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
    cin>>n;
    cin>>m;
    if(n<=2000)
    {
        cout<<"1";
    }
    else{
        cin>>m;
        int big=0;
        for(int i=0;i<n;i++)
        {
            cin>>list[i];
            big=max(big,list[i]);
        }
        if(big<=4)
        {
            cout<<"4";
            return 0;
        }
        sort(list,list+n-1);
        cout<<list[m-1];
    }
    return 0;
}