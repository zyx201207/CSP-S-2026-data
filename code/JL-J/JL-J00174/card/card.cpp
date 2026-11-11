
#include<iostream>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    // freopen mustn't '//' !
    bool A=true;
    int n,m;
    cin>>n>>m;
    int ans[10005]={0};
    int a[500][300]={0};
    int test[5000]={0};
    for(int i=1;i<=n;i++){
        cin>>test[i];
        if(!(test[i]>=test[i-1])){
            A=false;
        }
    }if(!A){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            a[i][j]=test[j];
        }
    }

    for(int t=1;t<=n;t++){
        int pd[10005]={0};
        int xb[10005]={0};
        bool have[10005]={0};
        int head=0;
        for(int i=t;i<=n;i++){
            if(!have[a[t][i]]){
                have[a[t][i]]=1;
                xb[a[t][i]]=head+1;
                if(pd[i]==0){
                    // head=i-t+1;
                    pd[head+1]=a[t][i];
                    head++;
                }
                //cout<<"do 1"<<endl;
                //for(int i=1;i<=m;i++){
                //    cout<<have[i];
                //}
            }
            else{
                //for(int i=1;i<=m;i++){
                //    cout<<have[i];
                //}
                cout<<endl;
                for(int j=xb[a[t][i]];j<=head;j++){
                    have[a[t][j]]=0;
                    pd[j]=0;
                }
                head=xb[a[t][i]];
                pd[head]=a[t][i];
                have[a[t][i]]=1;
                xb[a[t][i]]=head;
                //cout<<"head="<<head<<endl;
                //cout<<"do 2"<<endl;;
            }
            //cout<<"Pd:";
            //for(int i=1;i<=head;i++){
            //    cout<<pd[i];

            //}
            //cout<<endl;
        }
        //for(int i=1;i<=m;i++){
         //   if(have[i]) ans[i]++;
        //}
        //cout<<"next turn"<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
}
    else{
        bool flag[5000]={false};
        for(int i=1;i<=n;i++){
                if(test[i]==test[i+1]) continue;
            else{
            ans[test[i]]=i;
        }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<' ';
        }
    }
    return 0;
}
// yue yong neng bu neng cong wo nao zi li gun chu qu
// zen me you bian cheng 3,2,1 le aaaaaaa
// /fn/fn/fn
