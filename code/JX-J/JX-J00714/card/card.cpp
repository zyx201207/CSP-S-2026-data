#include <iostream>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdin);
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int b[m+1]={0};
    int s[n+1]={0};

    for(int i=1;i<=n;i++){
        int ans=1;
        for(int j=i;j<=n;j++){
            int bo=1;
            for(int ii=1;ii<=ans;ii++){
                if(s[ii]==a[i]){
                    ans=ii;
                    bo=0;
                    break;
                }
            }
            if(bo==1){
                ans+=1;
                s[ans]=a[i];
            }
           // for(int i=1;i<=ans;i++){
            //    cout<<s[i]<<" ";
            //}
        }
        for(int ii=1;ii<=ans;ii++){
            b[s[ii]]+=1;

        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
