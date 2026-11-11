#include<bits/stdc++>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    cin>>n;
    string S=0;
    for(int i=1;i<=n;i++)
    {
        int a1;
        string c1;
        cin>>a1>>c1;
        for(int j=1;j<=a1;j++)
        {
            S+=c1;
        }
    }
    for(int i=1;i<=S/2;i++)
    {
        if(S%2==0){
            for(int j=length.S;j>S/2;j--){
                if(S[i]==S[j]){
                    cout<<'0';
                }
                else{
                    S[j]=S[i];
                    sum++;
                }
            }
        }
        else{
            for(int j=length.S;j>S/2+1;j--){
                if(S[i]=S[j]){
                    cout<<'0'
                }
                else{
                    S[j]=S[i];
                    sum++;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
