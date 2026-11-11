#include<iostream>
using namespace std;
int main()
{
    freopen("subway.in","r",stdio);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int kou[m];
    for(int a=0;a<m;a++)
    {
        cin>>kou[a];
    }
    for(int a=0;a<n;a++)
    {
        int i;
        cin>>i;
        for(int k=0;k<i;k++)
        {
            int chufa,daoda;
            cin>>chufa>>daoda;
        }
    }
    for(int a=0;a<q;a++)
    {
        int qidian,zhongdian;
        cin>>qidian>>zhongdian;
        cout<<kou[qidian-1]+kou[zhongdian-1]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
