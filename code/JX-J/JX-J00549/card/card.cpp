#include<bits/stdc++.h>
using namespace std;
long long n,m,a;
vector<int>v1;
vector<int>v2;
map<int,int>ma;
map<int,int> m2;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        int d=v1.size(),b;
        for(int j=0;j<d;j++){
            if(a==v1[j]){
                b=j;
                for(int k=j;k<i;k++){
                    v2.push_back(v1[k]);
                    v1.pop_back();
                }
                break;
            }
        }
        v1.push_back(a);
    }
    for(auto o:v1){
//        cout<<o<<" ";
        ma[o]++;
    }
//    cout<<endl;
    for(int i=1;i<n;i++){
        int d=v2.size();
        for(int j=0;j<d;j++){
            int d1=v1.size();
            for(int k=0;k<d1;k++){
                if(v1[k]==v2[j]){
                    for(int l=k;l<d1;l++){
                        v2.push_back(v1[k]);
                        v1.pop_back();
                    }
                    break;
                }
            }
            v2.erase(v2.begin());
            v1.push_back(v2[j]);
        }
        for(auto o:v1){
//            cout<<o<<" ";
            ma[o]++;
        }
 //       cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ma[i]<<" ";
    }
    return 0;
}
