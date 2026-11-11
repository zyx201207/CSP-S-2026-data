#include<bits/stdc++.h>
using namespace std;
int n;
long long a,ans;
char c;
stack<pair<long long,char>>q3;
stack<pair<long long,char>>q1;
stack<pair<long long,char>>q2;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        q1.push({a,c});
        q3.push({a,c});
    }
    for(int i=1;i<=n;i++){
        long long a3=q3.top().first;
        char c3=q3.top().second;
        q2.push({a3,c3});
        q3.pop();
    }

    while(q2.size()){
        long long a1=q1.top().first,a2=q2.top().first;
        char c1=q1.top().second;
        char c2=q2.top().second;
        if(a1>a2){
            if(c1==c2){
                q2.pop();
                q1.pop();
                q1.push({a1-a2,c1});
            }
            else{
                ans+=a2;
                q2.pop();
                q1.pop();
                q1.push({a1-a2,c1});
            }
        }
        else if(a1<a2){
            if(c1==c2){
                q2.pop();
                q1.pop();
                q2.push({a2-a1,c2});
            }
            else{
                ans+=a1;
                q1.pop();
                q2.pop();
                q2.push({a2-a1,c2});
            }
        }
        else{
            if(c1==c2){
                q2.pop();
                q1.pop();
            }
            else{
                ans+=a2;
                q1.pop();
                q2.pop();
            }
        }
    }
    cout<<ans/2;
    return 0;
}
/*freopen
()/[]/{}
return 0
quanju/jubu
endl->\n
int->ll
*/
