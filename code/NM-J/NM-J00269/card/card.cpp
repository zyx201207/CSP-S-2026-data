#include<bits/stdc++.h>
using namespace std;
vector <long long> a;
vector <long long> game;
vector <long long> bj;
long long gs[500500];
/*
bool flag(int g,int a0) // g=j //a0=a0;
{
    for(int i=a0;i<=g;i++)
    {
        bj[i]++;
    }
    for(int i=a0;i<g;i++)
    {
        if(bj[i]>1)
        {
            return 1;
        }
    }
    return 0;
}
*/
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n=0,m=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int h=0;
        cin>>h;
        a.push_back(h);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            bj.clear();
            for(int l=0;l<j;l++)
            {
                bj[l]++;
                if(bj[l]>1)
                {
                    for(int g=0;g<j;g++)
                    {
                        game[g]=0;
                    }
                }
            }
            game.push_back(a[j]);
            if(game[j]==0)
            {
                continue;
            }
            else
            {
                gs[game[j]]++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<gs[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
