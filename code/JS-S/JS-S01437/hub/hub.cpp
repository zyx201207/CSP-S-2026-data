#include<bits/stdc++.h>
using namespace std;
struct lin{
    int l,r;
};
bool operator<(lin a,lin b){
    return a.l>b.l;
}
int main(){
    priority_queue<lin> q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        q.push({l,r});
    }
    while(!q.empty()){
        cout<<q.top().l<<" "<<q.top().r<<endl;
        q.pop();
    }
}