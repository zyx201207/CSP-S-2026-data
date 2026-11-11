#include<bits/stdc++.h>

using namespace std;
vector<pair<int,char>>v;
int main(){
    ifstream cin("string.in");
    ofstream cout("string.out");
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        char c;
        cin>>c;
        v.push_back({t,c});
    }
    long long c=0;
    int l=0,r=n-1;
    while(n>1){
        if(v[l].second==v[r].second){
            n--;
            if(v[l].first>v[r].first){
                v[l].first-=v[r].first;
                r--;
            }else if(v[l].first<v[r].first){
                v[r].first-=v[l].first;
                l++;
            }else{
                r--;
                l++;
                n--;
            }
        }else{
            n--;
            if(v[l].first>v[r].first){
                v[l].first-=v[r].first;
                c+=v[r].first;
                r--;
                //cout<<"2-1";
            }else if(v[l].first<v[r].first){
                v[r].first-=v[l].first;
                c+=v[l].first;
                l++;
                //cout<<"2-2";
            }else{
                c+=v[r].first;
                r--;
                l++;
                n--;
                //cout<<"2-3";
            }
        }
    }
    cout<<c;
    return 0;
}
