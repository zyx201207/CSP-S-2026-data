#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500011];
int num[500011];
int s[500011],len=0;
void find_num_move(int x){
    bool l=false;
    int k=len;
    for(int i=1;i<=k;i++){
        if(s[i]==x){
            l=true;
        }
        if(l){
            len=i-1;
            for(int j=i;j<=k;j++){
                s[j]=-1;
            }
            break;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        num[i+1]=0;
        s[i+1]=-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            s[j]=-1;
        }
        len=0;
        for(int j=i;j<=n;j++){
            find_num_move(a[j]);
            s[++len]=a[j];
        }
        for(int j=1;j<=len;j++){
            num[s[j]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<num[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
