#include<bits/stdc++.h>
using namespace std;
struct ww{
    long long a;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,i,n,j,ans=0,k,min_;
    cin>>n;
    ww m[n];
    for(i=0;i<n;i++){
        cin>>m[i].a>>m[i].c;
    }
    i=0;
    j=n-1;
    while(1){
        if(i==j || m[i].a==0 || m[j].a==0){
            break;
        }
        if(m[i].c != m[j].c){
            ans+=min(m[i].a,m[j].a);
        }
        min_=min(m[i].a,m[j].a);
        m[i].a-=min_;
        m[j].a-=min_;
        if(m[i].a==0){
            i++;
        }
        if(m[j].a==0){
            j--;
        }
/*
        for(k=0;k<n;k++){
            cout<<m[k].a<<" "<<m[k].c<<' ';
        }
        cout<<endl;
*/
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
