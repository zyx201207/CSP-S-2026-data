#include<bits/stdc++.h>
using namespace std;
const int N=10000010;
vector<int> a,b;
map<int,bool> ma;
map<int,int> maw;
map<int,int> maj;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    n+=1;
    for(int i=0;i<m;i++){
        ma[i]=false;
        maw[i]=0;
        maj[i]=0;
    }
    while(n--){
         for(int i=0;i<n;i++){
            b.push_back(a[i]);
            if(ma[a[i]]==false){
                ma[a[i]]=true;
                maw[a[i]]=b.size()-1;
            }
            else{
                for(int i=maw[a[i]];i<b.size();i++){
                    ma[b[i]]=false;
                }
                b.erase(b.begin()+maw[a[i]],b.end());
                b.push_back(a[i]);
                maw[a[i]]=b.size()-1;
                ma[a[i]]=true;
            }
        }
        for(int i=0;i<b.size();i++){
            maj[b[i]]++;
        }
        a.erase(a.begin());
    }
    for(int i=0;i<m;i++){
        cout<<maj[i];
    }
    return 0;
}
