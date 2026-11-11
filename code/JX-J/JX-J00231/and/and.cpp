#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],s;
priority_queue <long long> q;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        q.push(a[i]);
    }
    s = q.top();
    //cout << q.top() << " ";
    q.pop();
    for(int i = 2;i <= m;i++){
        //cout << s << " ";
        s &= q.top();
        //cout << q.top() << " ";
        q.pop();
     }
    cout << s;



    return 0;
}


