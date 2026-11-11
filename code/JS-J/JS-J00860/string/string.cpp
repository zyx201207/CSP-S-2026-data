#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+1;
struct node
{
    int g;
    char c;
};
vector<node>arr(N);
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int p;
    cin>>p;
    long long sum=0;
    long long cnt=0;
    for(int i=0;i<p;i++)
    {
        cin>>arr[i].g>>arr[i].c;
        sum+=arr[i].g;
    }
   int l=0,r=p-1;
   while(l<r)
   {
       int s=0;
       if(arr[l].c==arr[r].c&&arr[l].g==arr[r].g)
       {
           l++;
           r--;
       }
       if(arr[l].c==arr[r].c&&arr[l].g!=arr[r].g)
       {
           if(arr[l].g>arr[r].g)
            {
               arr[l].g-=arr[r].g;
               r--;
            }
           else{
                arr[r].g-=arr[l].g;
                l++;
           }
       }
       if(arr[l].c!=arr[r].c)
        {
            if(arr[l].g>arr[r].g)
            {
               cnt+=arr[r].g;
               arr[l].g-=arr[r].g;
               r--;
            }
            else{
                arr[r].g-=arr[l].g;
                cnt+=arr[l].g;
                l++;
            }
        }
   }
    cout<<cnt;
    return 0;
}
