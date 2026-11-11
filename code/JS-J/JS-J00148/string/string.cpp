#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int ipt[100005];
    char cipt[100005];
    int opt[100005];
    char copt[100005];
    int n,flag=0,us,in; scanf("%d",&n);
    long long s=0,s1=0,s2=0;
    for(int i=0;i<n;i++){
        scanf("%d",&ipt[i]);
        cin>>cipt[i];
        s+=ipt[i];
    }
    if(s%2==0) us=0;
    else us=1;
    s/=2;
    for(int i=0;i<n;i++)
    {
        s1+=ipt[i];
        if(s1>s && flag==0)
        {
            in=i;
            flag=1;
            if(us==0){
                opt[i+1]=s1-s;
                opt[i]=ipt[i]-opt[i+1];
                copt[i]=cipt[i];
                copt[i+1]=cipt[i];
            }
            else{
                opt[i+1]=s1-s-1;
                opt[i]=ipt[i]-opt[i+1]-1;
                copt[i]=cipt[i];
                copt[i+1]=cipt[i];
            }
        }
        else{
            opt[i+flag]=ipt[i];
            copt[i+flag]=cipt[i];
        }
    }
    int lft=in,rt=in+1;
    while(lft>=0)
    {
        int mini=min(opt[lft],opt[rt]);
        if(copt[lft]!=copt[rt]) s2+=mini;
        opt[lft]-=mini;
        if(opt[lft]==0) lft--;
        opt[rt]-=mini;
        if(opt[rt]==0) rt++;
    }
    cout<<s2;
    return 0;
}
