#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S;
	int L,n,a,b=1,ans=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            S[b]=c;
            b++;
        }

    }
    L=b;
    for(int i=1;i<=b;i++)
    {
        if(S[i]!=S[i+1])
        {
            ans++;
        }
        else
        {
            cout<<"1";
            return 0;
        }
    cout<<"1";
    return 0;
}
