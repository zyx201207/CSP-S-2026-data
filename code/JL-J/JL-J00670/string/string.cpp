#include<bits/stdc++.h>
using namespace std;
map<int,char>m;
int n,t[100],a,cnt;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t[i]>>c;
        for(int j=i;j<=t[i]+n;j++)
        m[i+j]=c;
    }
    for(int i=0;i<n;i++) a+=t[i];
    //for(int i=0;i<a+1;i++) cout<<m[i];
    int R=a,L=0;
    for(int i=0;i<a;i++)//a是长度
    {
        if(m[L]!=m[R]&&L<R) cnt++;
        L++,R--;
    }
    cout<<cnt;
	return 0;
}
