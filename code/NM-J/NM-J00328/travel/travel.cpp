#include<bits/stdc++.h>
using namespace std;
string sn,sm,n,m;
int a()
{
    if(n==m)
        return 1;
    else
        return 0;
}
int b()
{
    if(a()){
        if(sn[1]==sm[1]&&sn[0]==sm[0])
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
int c()
{
    if(b()){
        if(sn[2]<='c'&&sm[2]<='c')
            return 1;
        else if(sn[2]>'c'&&sm[2]>'c')
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
int d()
{
    if(c()){
        if(sn[2]+1==sm[2]||sm[2]+1==sn[2])
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>sn>>m>>sm;
    if(a())
    	cout<<1;
    else
    	cout<<0;
    if(b())
    	cout<<1;
    else
    	cout<<0;
    if(c())
    	cout<<1;
    else
    	cout<<0;
    if(d())
    	cout<<1;
    else
    	cout<<0;
    return 0;
}
