#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N],zd;
int main()
{
//	freopen("and.in","r",stdin);
 //   freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int s=0,x=a[i];
        string b="",d="";
        while(x!=0)
        {
            b+=char(x%2+48);
            x=x/2;
        }
        for(int j=i;j<i+m-1;j++)
        {
            int y=a[j+1];
            string c="";

            while(y!=0)
            {
                c+=char(y%2+48);
                y=y/2;
            }
            for(int k=0;k<max(b.size(),c.size());k++)
            {
                if(b[k]=='0'||c[k]=='0') d+='0';
                else d+='1';
            }
            reverse(d.begin(),d.end());
            b=d;
            d="";
        }
        reverse(b.begin(),b.end());
        for(int k=0;k<b.size();k++) s=s+(b[k]-'0')*pow(k,2);

        zd=max(s,zd);

    }
    cout<<zd;
	return 0;
}
