#include<bits/stdc++.h>
using namespace std;
/*输入的第一行包含一个正整数n
输入的第i+ 1 (1≤i≤n)行包含一个正整数ai和一个小写英文字母ci

1≤n≤2×10^5
i(1≤i≤n)，均有1≤ai≤10^9，且ci为小写英文字母
*/

//int a[200005],si[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    string s="";
    cin>>n;
    while(n--)
    {
        int ai;
        string si;
        cin>>ai>>si;
        for(int j=1;j<=ai;j++)
        {
            s+=si;
        }
    }

    int cnt=0,len=s.size();
    int left=0,right=len-1;

    while(left<=right)
    {
        if(s[left]!=s[right])cnt++;
        left++;
        right--;
    }


    cout<<cnt;



    /*
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
    }
    int cnt=0;
    int i=1;j=n;
    while(i<=j)
    {
        if(s[i]==s[j])
        {
            if(a[i]==a[j])continue;
            else cnt+=abs(a[i]-a[j]);
        }

        else
        {
            if(a[i]==a[j])cnt+=a[i];
            else
            {

            }
        }


        i++;
        j++;
    }*/



    return 0;
}
