#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1,c2;
    int arr[10];
    cin>>arr[0];
    cin>>arr[1];
    cin>>c1;
    cin>>arr[2];
    cin>>arr[3];
    cin>>c2;
    if(arr[0]==arr[2])
    {
       arr[5]=1;
    }
    else
    {
        arr[5]=0;
    }
    if(arr[1]==arr[3])
    {
        arr[6]=1;
    }
    else
    {
        arr[6]=0;
    }
    if(arr[1]>3&&arr[3]>3)
    {
        arr[7]=1;
    }
    else if(arr[1]<=3&&arr[3]<=3)
    {
        arr[7]=1;
    }
    else
    {
        arr[7]=0;
    }
    if(c1>'C'&&c2>'C')
    {
        arr[8]=1;
    }
    else if(c1<='C'&&c2<='C')
    {
        arr[8]=1;
    }
    else
    {
        arr[8]=0;
    }
    if(arr[5]==0)
    {
        arr[6]=0;
    }
    if(arr[6]==0)
    {
        arr[7]=0;
    }
    if(arr[7]==0)
    {
        arr[8]=0;
    }
    cout<<arr[5]<<arr[6]<<arr[7]<<arr[8];
    return 0;
}
