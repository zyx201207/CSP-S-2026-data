#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005];
long long chafen[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long q=1;q<=n;q++)
    {
        cin>>a[q];
    }
    sort(a,a+n);
    if(n<=5000)
    {
        for(long long q=1;q<n;q++)
        {
            chafen[q]=a[q+1]-a[q];
        }
        chafen[n]=0;
        long long suoxucishu=0;
        long long geshu=1;
        long long ans=0;
        for(long long q=1;q<n;q++)
        {
            for(long long w=q+1;w<=n;w++)
            {
                suoxucishu+=chafen[w-1]*geshu;
                if(suoxucishu>m)
                {
                    if(ans<geshu)
                    {
                        ans=geshu;
                    }
                    geshu=1;
                    break;
                }
                if(w==n)
                {
                    if(geshu+1>ans)
                    {
                        ans=geshu+1;
                    }
                }
                geshu++;
            }
            suoxucishu=0;
            geshu=1;
        }
        cout<<ans<<endl;
    }
    else{
        int cha=a[2]-a[1];
        for(int q=n;q>=1;q--)
        {
            if((q-1)*cha*q<=2*m)
            {
                cout<<q<<endl;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
