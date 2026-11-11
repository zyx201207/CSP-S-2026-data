#include <bits/stdc++.h>
using namespace std;
#define i64 long long
i64 n,startx=0,endx,ans,strl=0;
pair<i64,char> str[1919810];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    endx = n-1;
    for(i64 i = startx;i <= endx;i++)
    {
        cin >> str[i].first >> str[i].second;
        strl+=str[i].first;
    }
    //Croatia :]
    while(startx < endx)
    {
        if(str[startx].first < str[endx].first)
        {
            str[endx].first -= str[startx].first;
            ans+=(str[startx].second^str[endx].second)*str[startx++].first;
        }
        else if(str[startx].first > str[endx].first)
	{
            str[startx].first -= str[endx].first;
            ans += (str[startx].second ^ str[endx].second)*str[endx--].first;
        }
        else ans += (str[startx++].second ^ str[endx].second)*str[endx--].first;
    }
    cout << min(ans,(strl/2)) << endl;
    return 0;
}
