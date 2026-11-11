#include<iostream>;
using namespace std;
int main()
{
    int n,a,m,w,sum=0;
    cin>>n>>m;
    for(int a;a<=n;a++){
        cin>>a;
        if(m==a){
            w=a-m;
        }
        sum=w+=w;

       cout<<a<<w<<n;
    return 0;
}

