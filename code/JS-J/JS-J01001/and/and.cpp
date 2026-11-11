#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n,m,mx,al=0x7fffffff,res;
int num[200070];
vector<int> chose;
int dig_c[32];//dig count
bool d[32][200070];//yes or no
int d_y[32][200070];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>num[i];
        if(num[i]>mx)mx=num[i];
        al=al&num[i];
    }

    if(m==1)
    {
        cout<<mx;
        return 0;
    }//#6
    if(m==n)
    {
        cout<<al;
        return 0;
    }//#7
    
    for (int i = 1; i <= n; i++)
    {
        int j=0;
        while (num[i])
        {
            if(num[i]%2==1)
            {
                d[j][i]=1;
                d_y[j][dig_c[j]]=i;
                dig_c[j]++;
            }
            num[i]/=2;
            j++;
        }
    }

    bool flag=0;
    for (int i = 30; i >= 0; i--)
    {
        if (dig_c[i]<m)continue;//this digit is useless
        if(!flag)//get it
        {
            for (int j = 0; j < dig_c[i]; j++)
                chose.push_back(d_y[i][j]);
            res+=pow(2,i);//useful digit
            flag=1;
        }
        else
        {
            int cnt=0;
            for (int j = 0; j < chose.size(); j++)
                if(d[i][chose[j]]==1)cnt++;
            if(cnt>=m)//or it's useless
            {
                for (int j = 0; j < chose.size(); j++)
                    if(d[i][chose[j]]==0)chose.erase(chose.begin()+j);//remove useless nums
                res+=pow(2,i);
            }
        }      
    }
    
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 4; j >= 0; j--)
        {
            cout<<d[j][i]<<' ';
        }
        cout<<endl;
    }
    

    for (int i = 0; i < chose.size(); i++)
    {
        cout<<chose[i]<<' ';
    }
    cout<<endl;
    */
    cout<<res;

    return 0;
}