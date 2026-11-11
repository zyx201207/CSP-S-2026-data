#include<iostream>
#include<fstream>
int cards[500005];
int lasts[300005];
int ans[300005];
int main()
{
    std::ifstream fin("card.in");
    std::ofstream fout("card.out");
    int n,m;
   fin>>n>>m;
    for(int i=0;i<n;i++)
    {
        fin>>cards[i];
    }
    for(int i=0;i<n;i++)
    {
        int pos=0;
        for(int j=i;j<n;j++)
        {
            if(lasts[cards[j]]!=-1)
            {
                for(int k=i;k<n;k++)
                {
                    if(lasts[cards[k]]<pos && lasts[cards[k]]>lasts[cards[j]])
                    {
                        lasts[cards[k]]=-1;
                    }
                }
                pos=lasts[cards[j]];
            }
            else{
                lasts[cards[j]]=pos;
            }
            pos++;
        }
        for(int b=1;b<=m;b++)
        {
            if(lasts[b]!=-1) ans[b]++;
            lasts[b]=-1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        fout<<ans[i]<<" ";
    }
}
