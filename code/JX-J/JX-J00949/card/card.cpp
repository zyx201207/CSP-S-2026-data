#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
long long a[5005],b[1005];
int flag[3005];
deque<long long>deq;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i-1]<a[i])sum++;
    }
    if(sum==n){
        while(n!=0){
            cout<<n;
            n-=1;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            deq.push_front(a[i]);
            if(deq.empty()&&deq.front()==deq.back()){
                int x=deq.front();
                while(!deq.empty())deq.pop_front();
                deq.push_front(x);
            }else if(deq.size())b[deq.front()]++;
            else {
                b[1]++;
                b[2]++;
            }
        }
        cout<<b[1]<<" "<<b[2];
    }
    return 0;
}

