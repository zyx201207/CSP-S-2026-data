#include<bits/stdc++.h>

using namespace std;
map<int,bool>mp;
int main(){
 //   /*
    ifstream cin("card.in");
    ofstream cout("card.out");
//    */
    int n,m;
    int cnt[m+1];
    cin>>n>>m;
    vector<int>v;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v.push_back(t);
    }
    for(int i=0;i<n;i++){
            //cout<<"turn"<<i<<"\n";
        stack<int>s;
        for(int j=i;j<n;j++){
            if(mp[v[j]]==0){
                s.push(v[j]);
                mp[v[j]]=1;
            }else{
                while(!s.empty()&&s.top()!=v[j]){
                    mp[s.top()]=0;
                    s.pop();
                }
            }
        }

        while(!s.empty()){
            //cout<<s.top()<<" ";
            mp[s.top()]=0;
            cnt[s.top()]++;
            s.pop();
        }
        //cout<<"\n";

    }

    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
