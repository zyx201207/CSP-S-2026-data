#include<bits/stdc++.h>
using namespace std;
string num[200001];
void in(int n,int p){
    int t=0;
    while(n!=0){
        num[p][30-t]=char(n%2+48);
        n/=2;
        t++;
    }
    return;
}
int n,m,a[200001],ans;
vector<int> t;
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) num[n]="000000000000000000000000000000";
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) in(a[i],i);
    for(int i=1;i<=30;i++){
        for(int j=1;j<=n;j++){
            if(num[j][i]=='1'){
                t.push_back(j);
            }
        }
        if(t.size()>=m){
            for(int i=0;i<m;i++){
                if(i==0) ans=a[t[i]];
                else ans&=a[t[i]];
            }
            cout<<ans;
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
        else{
            t.erase(t.begin(),t.end());
            t.clear();
        }
    }
    cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}