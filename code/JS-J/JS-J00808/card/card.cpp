#include<bits/stdc++.h>
using namespace std;
const int TWT=300009;
int n,m;
int a[TWT];
int ans[TWT];
int l1st[TWT];
int num_place[TWT];
void start_from(int t){
    int end_of_the_1ist=0;
    for(int i=0;i<=m+1;i++){
        num_place[i]=1e9;
    }
    for(int i=t;i<=n;i++){
        if(num_place[a[i]]==1e9){
            num_place[a[i]]=end_of_the_1ist;
            l1st[end_of_the_1ist++]=a[i];
        }
        else{
            for(int j=end_of_the_1ist;j>=num_place[a[i]];j--){
                num_place[a[j]]=1e9;
                end_of_the_1ist=j;
            }
            end_of_the_1ist--;
            num_place[a[i]]=end_of_the_1ist;
            //cout<<end_of_the_1ist<<endl;
            l1st[end_of_the_1ist++]=a[i];
        }
    }
    for(int i=1;i<=m;i++){
        if(num_place[i]!=1e9){
            ans[i]++;
        }
    }
    //cout<<endl;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        start_from(i);
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
