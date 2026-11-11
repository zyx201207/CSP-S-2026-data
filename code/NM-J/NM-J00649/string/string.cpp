#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    vector<pair<int,char> > ve;
    for (int i = 0;i < n;++ i){
        int x;
        char y;
        scanf("%d %c",&x,&y);
        ve.push_back({x,y});
    }
    int i = 0,j = ve.size() - 1;
    ull cnt = 0;
    while (i < j){
        if (ve[i].second == ve[j].second){
            if (ve[i].first == ve[j].first){
                ++ i;
                -- j;
            }
            else if (ve[i].first > ve[j].first){
                ve[i].first -= ve[j --].first;
            }
            else {
                ve[j].first -= ve[i ++].first;
            }
        }
        else{
            if (ve[i].first == ve[j].first){
                cnt += (ull)ve[i].first;
                ++ i;
                -- j;
            }
            else if (ve[i].first > ve[j].first){
                cnt += (ull)ve[j].first;
                ve[i].first -= ve[j --].first;
            }
            else {
                cnt += (ull)ve[i].first;
                ve[j].first -= ve[i ++].first;
            }
        }
    }
    printf("%llu\n",cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
