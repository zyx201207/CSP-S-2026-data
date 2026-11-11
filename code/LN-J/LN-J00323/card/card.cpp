#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[1000000],s[1000000];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[a[i]]+=1;
    }
    for(int i=1;i<=m;i++)
    {
       cout<<s[i];
    }

	return 0;
}





