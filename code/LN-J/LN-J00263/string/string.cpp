
#include<bits/stdc++.h>
using namespace std;
int n,a;
string c,ans;
int sum=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    ans=' ';
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int i=1;i<=a;i++)
        {
            ans+=c;
        }
    }
    int len=ans.size();
    int j=len-1;
    for(int i=1;i<len;i++)
    {
        if(ans[i]!=ans[j])
            {
                sum++;
            }
            j--;
            if(i==j||i+1==j)
            {
                break;
            }
    }
    cout<<sum;
return 0;
}
