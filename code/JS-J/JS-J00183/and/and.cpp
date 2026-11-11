#include<iostream>
#include<fstream>
#include<vector>
long long ant[200005];
bool a[200005][32];
bool gg[32];
bool av[200005];
std::vector<int> v;
int main()
{
    std::ifstream fin("and.in");
    std::ofstream fout("and.out");
    int N,M;
    fin>>N>>M;
    for(int i=0;i<N;i++)
    {
        fin>>ant[i];
        v.push_back(i);
        av[i]=true;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;ant[i]!=0;j++){
        int k=ant[i]%2;
        if(k==1) a[i][j]=true;
        else a[i][j]=false;
        ant[i]/=2;
        }
    }
    for(int i=31;i>=0;i--)
    {
        int oink=0;
        for(int l=0;l<N;l++)
        {
            if(av[l] && a[l][i]) oink++;
        }
        if(oink>=M)
        {
            for(int l=0;l<N;l++)
            {
                if(!(a[l][i]))
                {
                    av[l]=false;
                }
            }
            gg[i]=true;
        }
    }
    long long ans=0;
    for(int i=31;i>=0;i--)
    {
        ans*=2;
        if(gg[i])
        {
            ans++;
        }
    }
    fout<<ans;
}
