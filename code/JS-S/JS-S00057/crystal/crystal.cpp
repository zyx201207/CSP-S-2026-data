#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
long long cry[500005]={0};
std::queue<long long> Q;
int main()
{
    std::ifstream fin("crystal.in");
    std::ofstream fout("crystal.out");
    long long n,m;
    fin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        fin>>cry[i];
    }
    std::sort(cry,cry+n);
    long long cur_size=0;
    long long max_size=0;
    long long num=0;
    for(long long j=1;j<n;j++)
    {
        cur_size+=(num+1)*(cry[j]-cry[j-1]);
        Q.push(j-1);
        num++;
        long long v=Q.front();
        while(cur_size>m)
        {
            cur_size-=(cry[j]-cry[v]);
            Q.pop();
            v=Q.front();
            num--;
        }
        max_size=std::max(max_size,num);
    }
    fout<<max_size+1;
}
