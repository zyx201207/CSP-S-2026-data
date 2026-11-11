#include <iostream>
#include <stack>
#include <map>
using namespace std;
stack<int> s;
map<int ,bool> p;
map<int,int> mp;
int a[1000010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i =1 ;i<= m ; i++){
        p[i] = 0;
        mp[i] = 0;
    }
    for(int i = 1 ; i<= n ; i++) cin>>a[i];
    for(int i = 1 ; i<=  n ;i++){
        for(int j =1 ;j<= m ; j++){
            p[j] = 0;
            mp[j] = 0;
        }
        while(!s.empty()) s.pop();
        for(int j = i ; j <= n;j++){
            if(!p[a[j]]){
                s.push(a[j]);
                p[a[j]] = 1;
            }
            else{
                while(true){
                    if(s.top() == a[j]){
                        s.pop();
                        break;
                    }
                    p[s.top()]=0;
                    s.pop();
                }
                s.push(a[j]);
            }
            if(j == n){
                for(int k =1 ; k<= m ; k++){
                    if(p[k]) mp[k]++;
                }
            }
        }
    }
    for(int i = 1  ; i<= m ;i++)cout<<mp[i]<<' ';
    return 0;
}
