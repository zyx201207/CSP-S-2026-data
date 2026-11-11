#include<bits/stdc++.h>
using namespace std;
int d(int a,int b,vector<int> df)
{
    vector<long long> a1,b1;
    long long ma,mb
    while(a!=0)
    {
        a1.push_back(a%2);
        a=(a-(a%2))/2
        ma+=1;
    }
    while(b!=0)
    {
        b1.push_back(b%2);
        b=(b-(b%2))/2
        mb+=1;
    }
    for(int i=max(ma,mb)-1;i>=0;i++)
    {
        if(a1[i]==1 && b1[i]==1)
        df[i]=1;
        else
        df[i]=0;
    }
    return df; 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n,m;
    vector<long long> arr;
    for(int i=0;i<n;i++)
    {
        long long s;
        cin>>s;
        arr.push_back(s);
    }
    int k=0;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{

    		vector<int> df;
    		if(k<d(n[i],n[j],df))
    		k=d(n[i],n[j],df);
		}
	}
	cout<<k<<endl;

}
