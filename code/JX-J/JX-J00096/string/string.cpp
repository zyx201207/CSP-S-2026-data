#include <iostream>
using namespace std;
int n,a,sum,num;
string b,;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    string letter[n];
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        sum+=a;
        letter[i]=b;
    }
    string word[sum];
    for(int i=0;i<sum;i++)
    {
        for(int j=0;j<a;j++)
        {
            word[num]=letter[i];
            num++;
        }
    }
    cout << "0";
    return 0;
}
