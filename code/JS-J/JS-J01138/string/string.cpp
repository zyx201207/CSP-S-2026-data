#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long all=0;
    cin>>n;
    vector<pair<long long,char>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        all+=v[i].first;
    }
    long long cnt=0;
    int i=-1,j=n;
    long long leftcnt=0,rightcnt=0;
    while(i<j){
        long long x=leftcnt-rightcnt;
        if(x<0){
            i++;
            leftcnt+=v[i].first;
            if(v[i].second!=v[j].second) cnt+=min(-x,v[i].first);
        }
        else if(x>0){
            j--;
            rightcnt+=v[j].first;
            if(v[i].second!=v[j].second) cnt+=min(x,v[j].first);
        }
        else{
            i++;
            leftcnt+=v[i].first;
        }
    }
    cout<<cnt<<endl;
    return 0;
}