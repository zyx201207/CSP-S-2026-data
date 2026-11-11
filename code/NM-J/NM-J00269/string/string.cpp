#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    vector<char> a;
    int k=0;
    char c=0;
    for(int i=0;i<n;i++)
    {
        cin>>k>>c;
        for(int j=0;j<k;j++)
        {
            s+=c;
        }
    }
    long long ans=0;
    long long i=0,j=s.size();
    while(i<j)
    {
    	j--;
    	i++;
        if(s[i]!=s[j])
        {
            s[j]=s[i];
            ans++;
        }

    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
