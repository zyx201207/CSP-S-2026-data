#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int N = 2e5+10;

int n,m;
int a[N];
map<int,int> mp;
//multiset<int> s;
vi v;
int b[40];
int main(){
    //1.052743s
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        mp[a[i]]++;
        //s.insert(a[i]);
    }
    for (int i = 30;i >= 0;i--){
        v.clear();
        int sum = 0;
        for (auto y : mp){
            if (y.first&(1<<i)){
                sum += y.second;
            }
            else {
                v.push_back(y.first);
            }          
        }
        /*for (auto y : s){
            if (y&(1<<i)){
                sum++;
            }
            else {
                v.push_back(y);
            }
        }*/
        if (sum >= m){
            b[i] = true;
            for (auto y : v){
                mp.erase(y);
            }
        }
    }   
    int ans = 0;
    for (int i = 30;i >= 0;i--){
        ans = ans*2+b[i];
    }
    printf("%d\n",ans);
    //printf("Time : %d",int(clock()));


    return 0;
}