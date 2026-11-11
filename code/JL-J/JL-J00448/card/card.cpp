#include<bits/stdc++.h>
using namespace std;
int a[500001];
int r[300001];
int M[300001];
int top=0;
int n,m;
void clean(){
    for(int i=0;i<=top;i++){
        r[i]=0;
    }
    top=0;
}
void play(int p){
    for(int i=p;i<n;i++){
        bool bk=0;
        for(int j=0;j<top;j++){
            if(a[i]==r[j]){
                bk=1;
                clean();
                r[top++]=a[i];
                continue;
            }
        }
        if(bk==0){
            r[top++]=a[i];
        }
        bk=0;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int i=0;i<top;i++){
            M[r[i]]++;
        }
        clean();
        play(i);

    }
    for(int i=1;i<=m;i++){
        cout<<M[i]<<' ';
    }

    fclose(stdin);
    fclose(stdout);



    return 0;
}
