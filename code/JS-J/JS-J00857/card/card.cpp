#include <bits/stdc++.h>
using namespace std;
int check_k(int* first,int* last,int k){
    if(first>last){
        return -1;
    }
    int* i;
    for(i=first;i<=last;i++){
        if( (*i) ==k){
            return (i-first)+1;
        }
    }
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],counts[300005],flags[300005];
    int table[500005],used=0;
    cin>>n>>m;
    memset(counts,0,sizeof(counts));
    memset(flags,false,sizeof(flags));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        used=0;
        memset(table,0,sizeof(table));
        memset(flags,false,sizeof(flags));
        for(int j=i;j<=n;j++){
            int pos=check_k(table+1,table+used,a[j]);
            if(pos==-1){
                table[used+1]=a[j];
                used++;
                //cout<<"a[j]&&used"<<a[j]<<" "<<used<<endl<<"now tables:";
                //for(int s=1;s<=used;s++){
                //    cout<<table[s]<<" ";
                //}
                //cout<<endl;
            }
            else{
                used=pos;
                table[pos]=a[j];
                //cout<<"pos"<<pos<<endl<<"now tables:";
                //for(int s=1;s<=used;s++){
                //    cout<<table[s]<<" ";
                //}
                //cout<<endl;
            }
        }
        for(int j=1;j<=used;j++){
            if(!flags[table[j]]){
                counts[table[j]]++;flags[table[j]]=true;
                //cout<<"table"<<table[j]<<" ";
            }
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<counts[i]<<" ";
    }
    return 0;
}
