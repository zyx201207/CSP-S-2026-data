#include<iostream>
#include<fstream>
#include<climits>
struct duan{
    long long lengt;
    char a;
};
duan duans[200005];
int main()
{
    std::ifstream fin("string.in");
    std::ofstream fout("string.out");
    int N;
    fin>>N;
    long long ans=0;
    for(int i=0;i<N;i++)
    {
        fin>>duans[i].lengt>>duans[i].a;
    }
    duans[N].lengt=0;
    duans[N].a='_';
    int head=0;
    int tail=N;
    bool is_left=true;
    long long lefs=0;
    long long righs=0;
    while(head<=tail)
    {
        long long leftto=lefs;
        long long rightto=righs;
        if(is_left){
            leftto+=duans[head].lengt;
            if(leftto<=rightto)
            {
                if(duans[head].a != duans[tail].a) ans+=duans[head].lengt;
                lefs=leftto;
                righs=righs-lefs;
                lefs=0;
                head++;
            }
            else{
                if(duans[head].a!=duans[tail].a) ans+=rightto-lefs;
                lefs=leftto;
                lefs=lefs-righs;
                righs=0;
                is_left=false;
                tail--;
            }
        }
        else{
             rightto+=duans[tail].lengt;
            if(rightto<=leftto)
            {
                if(duans[head].a != duans[tail].a) ans+=duans[tail].lengt;
                righs=rightto;
                lefs=lefs-righs;
                righs=0;
                tail--;
            }
            else{
                if(duans[head].a!=duans[tail].a) ans+=leftto-righs;
                righs=rightto;
                righs=righs-lefs;
                lefs=0;
                is_left=true;
                head++;
            }
        }
    }
    fout<<ans;
}
