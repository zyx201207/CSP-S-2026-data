#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector <int> a,b;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
//    for(int i=0;i<n;i++)
//    {
//        while(a[i]>0)
//        {
//            b.push_back(a[i]%2);
//            a[i]/=2;
//        }
//        b.push_back(2);
//    }
//    for(int i;i<b.size();i++)
//    {
//
//    }
    cout<<a[a.size()-1]<<endl;
    return 0;
}
