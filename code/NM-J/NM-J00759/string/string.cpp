#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0,h=0;
    vector<string> arr;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long q;
        string s;
        cin>>q>>s;
        if(q%2==0)
        sum+=(q/2);
        h+=q;
        for(int j=0;j<q;j++)
            arr.push_back(s);
    }
    vector<string> arr2;
    for(int i=h-1;i>=0;i--)
    arr2.push_back(arr[i]);
    if(arr==arr2)
    cout<<0<<endl;
	else
	cout<<sum<<endl;
    return 0;
}
