#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool b[300005];
stack<int> sta;
vector<int> desk;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        //printf("1");
        for(int k=i;k<=n;k++){
            int x=a[k];
            //printf("%d ",x);
            if(!b[x]){//not on the desk
                b[x]=1;
                desk.push_back(x);
            }else{//on the desk
                int i=0;
                while(desk[i]!=x)i++;
                for(int j=i;j<=desk.size();j++){
                    b[desk[i]]=0;
                    desk.erase(desk.begin()+i);
                }
                b[x]=1;
                desk.push_back(x);
            }
//            for(int i=0;i<desk.size();i++){
//                printf("%d ",desk[i]);
//            }
            //printf("\n");
        }
        for(int i=0;i<desk.size();i++)
                ans[desk[i]]++;
        desk.clear();
        memset(b,0,sizeof(b));
        //printf("over\n");
    }
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
    return 0;
}
