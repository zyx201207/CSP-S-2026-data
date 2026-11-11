#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
        vector<int>arr;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        vector<vector<int>>a;
        vector<vector<int>>t;
        for(int j=0;j<n;j++){
            int h;
        cin>>h;
            int ai[h],ti[h];
            for(int i=0;i<h;i++){
            cin>>ai[i]>>ti[i];
            }
            a.push_back(ai);
            t.push_back(ti);
        }
        int ans=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(a[1])
            }
        }
        for(int j=0;j<q;j++){
            int Begin,End;
            cin>>Begin>>End;
            int sum=0;
            sum=arr[Begin-1]+arr[End-1];

        }
    return 0;
}
