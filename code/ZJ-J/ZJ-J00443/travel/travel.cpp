#include<bits/stdc++.h>
using namespace std;
short int op[]={1,2,3,5,6};
string c1,s1,c2,s2;
bool flag1,flag2,flag3,flag4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    string p1=s1.substr(0,2),p2=s2.substr(0,2);
	char z1=s1[2],z2=s2[2];
    if(c1==c2)
        flag1=1;
    if(c1==c2&&p1==p2)
        flag2=1;
    if(c1==c2&&p1==p2&&(((z1=='A'||z1=='B'||z1=='C')&&(z2=='A'||z2=='B'||z2=='C'))||((z1=='D'||z1=='F')&&(z2=='D'||z2=='F'))))
    	flag3=1;
    short int l1=op[z1-'A'],l2=op[z2-'A'];
    if(z1>z2) swap(l1,l2);
    if(l1==(l2-1)&&p1==p2&&c1==c2)
    {
    	flag4=1;
	}
	cout<<flag1<<flag2<<flag3<<flag4;
    return 0;
}