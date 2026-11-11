#include <bits/stdc++.h>
using namespace std;
typedef int re;typedef long long ll;
re n,m,a[500005],pos[300005],cnt[300005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (re i = 1;i <= n;i++){
        cin >> a[i];
        pos[a[i]] = (pos[a[i]] != 0 ? pos[a[i]] : i);
    }
    for (re i = 1;i <= n;i++){
        deque <re> q;
        for (re j = 1;j <= n;j++) q.push_back(a[i]);
        for (re j = i;j <= n;j++){
            for (re k = 1;k <= (int)q.size() - pos[a[i]] + 1;k++){
                re u = q.back();
                if (pos[u] >= pos[a[i]]) pos[u] = 2 * n + 1;
                q.pop_back();
            }
            pos[a[j]] = (int)q.size() + 1;
        }
        while (!q.empty()){
            cnt[q.front()]++;
            q.pop_front();
        }
    }
    for (re i = 1;i <= m;i++) cout << cnt[i] << ' ';
    return 0;
}
/*
i don't know if i can cin >> Chinese
i don't know who can translate it,hope that there be someone can read it
T1 O(1) shen mi xiao mo ni(easier than 2025T2)
T2 O(n) shuang zhi zhen?
T3 O(nlogn) shu wei mei ju(as lieqi as 2025T3)
   tnnd because i forget to delete the size behind vector
   there are a lot of 0 in vector!!!
   result in now 10:48(8:56 started,i'm hopeless that time)
T4 idk,i want to give up
   o(n^2) will lead to TLE
   i tkink if i have the ans when i = 1,i can get i = 2~n
   but it seems impossible
   szsz?idk if j need szsz
   now it's 11:00,i have no idea
   11:32 i want to pf
   as the saying goes:bl will lead to surprise,db can be the 1st of your province

all in all,i hope for 280+pts
thank you ,CCF(i must apprecate CCF to get more score)
I still have a long journey on C++(i also S)
I have enough time to learn more because of grade 8(4 years to AFO)
I recommend <DAYBREAK FRONTLINE> & <Children Record> & <non-breath oblige>,you can have a try
I like to play<project sekai> & <phigros> & <delta action>
i only want to tell you in the result of idk what can i do
*/
