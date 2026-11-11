#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0;
long long head=0,tail=0;
long long p1=-1,p2=0;
char s[200005];
long long nums[200005];
int main(){
    freopen("string/string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    p2=n;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i]>>s[i];
    }
    for(int i=0;i<2*n;i++)
    {
        if(head==0)
        {
            p1++;
            if(p1==n)
            {
                break;
            }
            head+=nums[p1];
        }
        if(tail==0)
        {
            p2--;
            if(p2==-1)
            {
                break;
            }
            tail+=nums[p2];
        }
        int m=min(head,tail);
        if(s[p1]!=s[p2])
        {
            cnt+=m;
        }
        head-=m;
        tail-=m;
    }
    cout<<cnt/2;
    return 0;
}