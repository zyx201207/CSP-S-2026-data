#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    vector<int>a;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    vector<int>b;
    int sum[100086]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b.push_back(a[j]);
        }
        vector<int>c;
        for(int j=i;j<n;j++){
            c.push_back(b[j]);
            for(int w=0;w<c.size()-1;w++){
                if(c[w]==b[j]){
                    for(int ww=w;ww<c.size();ww++){
                        c.pop_back();
                    }
                }
            }
        }
        for(int j=0;j<c.size();j++){
            sum[c[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<' ';
    }
    return 0;
}
