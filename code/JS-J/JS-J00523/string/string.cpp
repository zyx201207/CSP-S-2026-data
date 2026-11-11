#include<bits/stdc++.h>
using namespace std;
char ch[200003];
int num[200003];
long long tot;
int n;
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i]>>ch[i];
    }
    //cout<<tot<<"\n";
    //long long mid=(tot+1)/2;

    int left=1,right=n;
    char lc=ch[left],rc=ch[right];  //characters
    int ln=num[left],rn=num[right]; //numbers
    while(left<=right)
    {
        //cout<<"left:"<<left<<" ;right:"<<right<<"\n";
        lc=ch[left];
        rc=ch[right];
        if(ln==0)
        {
            left++;
            ln=num[left];
            continue;
        }
        if(rn==0)
        {
            right--;
            rn=num[right];
            continue;
        }
        //cout<<ln<<lc<<" "<<rn<<rc<<"\n";
        if(lc!=rc)
        {
            tot++;
        }
        ln--,rn--;
    }
    cout<<tot;
    return 0;
}