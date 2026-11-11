#include<bits/stdc++.h>
using namespace std;
int d;
struct node{
    int kou[25],now=0,tim2[505];
}a[505];
int tim[500010];
struct line{
    int next[25],sum=0,together[25];
}exist[500050];
int answer,ans;
void work(int l,int r)
{
    bool boo=0;
    int i,j;
    for(i=1;i<=a[l].now;i++)
    {
        for(j=1;j<a[r].now;j++)
        {
            if(a[l].kou[i]==a[r].kou[j])
            {
                boo=1;
                break;
            }
        }
        if(boo)
        {
            break;
        }
    }
    if(boo)
    {
        answer+=a[l].tim2[a[l].kou[i]]+a[r].tim2[a[r].kou[j]];
        ans=min(ans,answer);
        answer-=a[l].tim2[a[l].kou[i]]+a[r].tim2[a[r].kou[j]];
        return;
    }
    else
    {
        for(i=1;i<=exist[l].sum;i++)
        {
            answer+=a[exist[l].next[i]].tim2[exist[l].together[i]]+a[l].tim2[exist[l].together[i]];
            work(exist[l].next[i],r);
            answer-=a[exist[l].next[i]].tim2[exist[l].together[i]]+a[l].tim2[exist[l].together[i]];
        }
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&tim[i]);
    }
    int num,num2;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num);
        int past;
        while(num--)
        {
            past=num2;
            scanf("%d",&num2);
            exist[num2].next[++exist[num2].sum]=past;
            exist[past].next[++exist[past].sum]=num2;
            exist[past].together[exist[past].sum]=exist[num2].together[exist[num2].sum]=i;
            a[num2].kou[++a[num2].now]=i;
            scanf("%d",&a[num2].tim2[a[num2].kou[a[num2].now]]);
        }
    }
    int l,r;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&l,&r);
        answer=tim[l]+tim[r];
        ans=1000010;
        work(l,r);
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
}
