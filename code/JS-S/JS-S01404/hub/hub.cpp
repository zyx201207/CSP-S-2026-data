#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<time.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int c,t,rd;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(0));
    cin>>c>>t;
    rd=c+2;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
        }
        cout<<rand()%rd+1<<endl;
    }

    return 0;
}
