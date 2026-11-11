#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
stack<int> s;
long long a[N];
long long m1[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i =1;i <= n;i++){
        s.push(a[i]);
        for(int j = 0;j <i;j ++){
        if(a[j] == s.top()){
                s.pop();
            while(s.top() != a[j]){
                s.pop();
            }
             if(!s.empty()){
            s.pop();
        }
        stack<int> s2;
        while(!s.empty()){
        s2.push(s.top());
        s.pop();
        }
        s.push(a[i]);
        while(!s2.empty()){
        s.push(s2.top());
        s2.pop();
        }
        continue;
        }

    }
    while(!s.empty()){
        m1[s.top()] += 1;
        s.pop();
    }
    }
    for(int i = 1;i<= m;i++){
        cout << m1[i] << " ";
    }
   return 0;
}
