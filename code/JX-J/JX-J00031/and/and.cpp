#include <bits/stdc++.h>
using namespace std;
long a[200001]={0};
int main()
{
    int n,m,num=0,snum=0;
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            snum=a[i]&&a[j];
            num=max(num,a[i]&&a[j]);
            cout<<" "<<snum<<" ";
            cout<<a[i]&&a[j];
        }
    }
    cout<<num<<endl;
	return 0;
}
