#include<iostream>
#include<fstream>
struct node{
    int c,p;
    char z;
};
node a,b;
bool check(char l,char r)
{
    if(l<='C'&&r<='C')
        return true;
    if(l>='D'&&r>='D')
        return true;
    return false;
}
int main()
{
    std::freopen("travel.in","r",stdin);
    std::freopen("travel.out","w",stdout);
    std::string c1,s1,c2,s2;
    std::cin>>c1>>s1>>c2>>s2;
    a.c=(((c1[0]-'0')*10)+(c1[1]-'0'));
    b.c=(((c2[0]-'0')*10)+(c2[1]-'0'));
    a.p=(((s1[0]-'0')*10)+(s1[1]-'0'));
    b.p=(((s2[0]-'0')*10)+(s2[1]-'0'));
    a.z=s1[2];
    b.z=s2[2];
    if(a.c==b.c)
    {
        std::cout<<1;
        if(a.p==b.p)
        {
            std::cout<<1;
            if(check(a.z,b.z))
            {
                std::cout<<1;
                if(std::abs((a.z-'A')-(b.z-'A'))==1)
                    std::cout<<1;
                else
                    std::cout<<"0";
            }
            else
                std::cout<<"00";
        }
        else
            std::cout<<"000";
    }
    else
        std::cout<<"0000";
    return 0;
}
