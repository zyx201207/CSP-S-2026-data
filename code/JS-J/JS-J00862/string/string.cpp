#include <bits/stdc++.h>
using namespace std;

struct Node{
    int num;
    char zm;
};

bool cmp(Node dd,Node ff)
{
    dd.zm<ff.zm;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n; cin>>n; Node a[n+5];

    if(n==1)  {cout<<0;return 0;}
    if(n==2)
    {
        int num1,num2; char zm1,zm2; cin>>num1>>zm1>>num2>>zm2;
        string s;
        for(int i=0;i<num1;i++) s+=zm1;
        for(int i=0;i<num2;i++) s+=zm2;
        int cnt=0;
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                cnt++;
            i++,j--;
        }
        cout<<cnt; return 0;
    }
    int ncnt=0; long long allnum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].num>>a[i].zm;
        allnum+=a[i].num;
        if(a[i].num==1) ncnt++;
    }
    if(ncnt==n){cout<<n/2; return 0;}

    string s;
    for(int i=0;i<n;i++)
        for(int j=0;j<a[i].num;j++)
            s+=a[i].zm;

    int i,j;
    if(s.length()%2==0) i=s.length()/2-1,j=s.length()/2;
    else i=s.length()/2,j=s.length()/2;

    long long cnt=0;
    while(i>=0 and j<s.length())
    {
        if(s[i]!=s[j]) cnt++;
        i--,j++;
    }
    cout<<cnt;
    return 0;
}
