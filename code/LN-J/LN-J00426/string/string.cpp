#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n,cnt;
string str;
pair<int,int> a[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char ch;
        cin>>a[i].first>>ch;
        a[i].second = ch-'a'+1;
    }
    for(int i=1,j = n;i<j;)
    {
        if(a[i].second!=a[j].second){
            if(a[i].first<a[j].first){
                cnt+=a[i].first;
                a[j].first -= a[i].first;
                i++;
            }
            else if(a[i].first>a[j].first){
                cnt+=a[j].first;
                a[i].first -= a[j].first;
                j--;
            }
            else{
                cnt+=a[i].first;
                i++;
                j--;
            }
        }
        else{
            if(a[i].first<a[j].first){
                a[j].first -= a[i].first;
                i++;
            }
            else if(a[i].first>a[j].first){
                a[i].first -= a[j].first;
                j--;
            }
            else{
                i++;
                j--;
            }
        }
    }
    cout<<cnt;

    return 0;
}
