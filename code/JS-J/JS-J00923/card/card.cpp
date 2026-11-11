#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[m]={0};
    int card[n];
    for(int i=0;i<n;i++)
    {
        cin>>card[i];
    }
    for(int i=0;i<n;i++)
    {
        int b[n]={0},head=0;
        for(int j=i;j<n;j++)
        {
            for(int k=0;k<head;k++)
            {
                if(b[k]==card[j])
                {
                    for(int z=k;z<head;z++)
                    {
                        b[z]=0;
                    }
                    head=k;
                    break;
                }
            }
            b[head]=card[j];
            head++;
        }
        for(int j=0;j<head;j++)
        {
            a[b[j]-1]++;
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}