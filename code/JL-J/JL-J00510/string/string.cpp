#include <bits/stdc++.h>
using namespace std;
struct str{
    int n;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,s=0;
    str x[1005],s1[1005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i].n>>x[i].c;
    }

    for(int i=0;i<n/2;i++){
        s1[i]=x[i];
    }
    for(int i=n/2,j=n/2-1;i<n;i++,j--){
        s1[i]=x[j];
    }
    for(int i=0;i<n;i++){
        printf("%d %c\n%d %c\n\n",s1[i].n,s1[i].c,x[i].n,x[i].c);
        if(s1[i].c!=x[i].c){
            s+=x[i].n;
        }
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
