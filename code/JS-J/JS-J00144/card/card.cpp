#include <bits/stdc++.h>
using namespace std;
const int MAXN= 5e5+5;//here
const int MAXM=3e5+5;
//const int MOD= ;

//int T;
int n,m;
int a[MAXN];
vector<int> pos[MAXM];

int les[MAXM];//shangyigeweizhi
struct node{
    int l;//muqianzuizuoduandeyigezuobiao

};
int ans[MAXM];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*cin>>T;
    while(T--){

    }*/
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];


    }
    //vector<pair<int,char> >flag[m+1];
    vector<int>ans(m+1,0);
    for(int i=1;i<=n;i++){
        memset(pos,0,sizeof(pos));
        int l=i,r=i;
        while(r<=n){

            //else{
            if(pos[a[r]].size()!=0){
                while(l<=r){
                    if(pos[a[l]].size()!=0){
                        pos[a[l]].pop_back();}
        //        flag.pop_front();//dao l meile
                    l++;

                }
            }
            pos[a[r]].push_back(r);
               // pos[a[r]].push_back(r);
            //}
            r++;
        }
        for(int j=1;j<=m;j++){
            if(pos[j].size()!=0){
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
