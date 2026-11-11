#include<bits/stdc++.h>
using namespace std;
int x,y,a[1000000],b[1000000],c[1000000],ans[1000000];
vector< pair<int,int> >v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    scanf("%d%d",&x,&y);
    for(int i=0;i<x;i++){
        scanf("%d",&a[i]);
    }
    for(int i=x-1;i>=0;i--){
        while(c[a[i]]>0){
            c[v.back().first]--;
            if(c[v.back().first]==0){
                ans[v.back().first]+=v.back().second-i;
            }
            v.pop_back();
        }
        v.push_back({a[i],i});
        c[a[i]]++;
    }
        while(v.size()!=0){
            c[v.back().first]--;
            if(c[v.back().first]==0){
                ans[v.back().first]+=v.back().second+1;
            }
            v.pop_back();
        }
        for(int i=1;i<=y;i++){
            printf("%d ",ans[i]);
        }
    return 0;
}
