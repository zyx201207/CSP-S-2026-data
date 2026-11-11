#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long cnt=0;
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<long long>a;
    string s;
    int len=s.length();
    int np=0;
    for(int i=0;i<n;i++)// cin
    {
        int x;char c;
        cin>>x>>c;
        cnt+=x;
        len=s.length();
        if(i!=0)
        {
            if(c==s[len-1])
            {
                a[np]+=x;
            }
            else
            {
                np++;
                s+=c;a.push_back(x);
            }
        }
        else    s+=c,a.push_back(x);
    }
    int idx=a.size()-1;
    long long cnt1=0;
    for(int i=0;i<a.size();i++)
    {
        cnt1+=a[i];
        if(cnt1>=cnt/2)
        {
            idx=i;
            break;
        }
    }
    cnt=0;
    int i=0,j=len-1;
    if(i==j)
    {
        cout<<0;
        return 0;
    }
    while(1)
    {
        if(i==j)    break;
        if(abs(i-j)==1) break;
        //cout<<i<<" "<<j<<" "<<cnt<<endl;
        if(s[i]==s[j])
        {
            //cout<<s[i]<<s[j]<<endl;
            if(s[i]<s[j])
            {
                a[j]-=i;
                i++;
            }
            if(s[i]==s[j])
                i++,j--;
            if(s[i]>s[j])
            {
                a[i]-=a[j];
                j--;
            }
        }
        else
        {
            if(a[i]>a[j])
            {
                cnt+=a[j];
                a[i]-=a[j];
                s[len-1]=' ';
                len--;
                j--;
            }
            if(a[i]==a[j])
            {
                cnt+=a[j];
                len-=2;
                i++,j--;
            }
            if(a[i]<a[j])
            {
                cnt+=a[i];
                a[j]-=a[i];
                s[i]=' ';
                len--;
                i++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
