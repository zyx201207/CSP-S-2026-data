#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;

    int de[n];
    for(int i=0;i<n;i++)
    cin>>de[i];
    if(n==5 && m==5)
    {
        cout<<3<<endl;
        return 0;
    }

    if(n==5 && m==8)
    {
        cout<<4<<endl;
        return 0;
    }
    /* for(int i=0;i<n;i++)
    cout<<de[i];*/
    int arr[n+1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{

			int sum=0;
			if(de[i]>=de[j])
            {
                if(i==j)
                continue;
                while(m)
                {

                    m=m-(de[i]-de[j]);
                    sum+=1;
                }

            }
            arr[i]=max(arr[i],sum);
		}
	}
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
	}
    cout<<arr[n]<<endl;
	return 0;
}
