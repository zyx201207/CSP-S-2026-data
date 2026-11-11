#include<bits/stdc++.h>
using namespace std;
pair<int,char>c[200010];
long long n,q;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>c[i].first>>c[i].second;
    if(n==2){
        if(abs(c[1]-c[2])%2)cout<<min(c[1].sise(),c[2].size())-1;
        else cout<<min(c[1].sise(),c[2].size());
        return 0;
    }
    int i=1,j=n,a=c[1].first,z=c[j].first;
    while(i<=j){
        if(a>z){
            if(c[i].second!=c[j].second)q+=c[j].first;
            z+=c[j].first;
            j--;
        }
        if(a==z){
            if(c[i].second!=c[j].second)q+=c[j].first;
            z+=c[j].first;
            a+=c[i].first;
            j--;
            i++;
        }
        if(a<z){
            if(c[i].second!=c[j].second)q+=c[i].first;
            a+=c[i].first;
            i++;
        }
    }
    cout<<q;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
