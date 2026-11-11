#include<bits/stdc++.h>
using namespace std;
struct q{
    int id;
    string a;
}x[20005];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i].id>>x[i].a;
    }
    string s=x[0].a;
    int flag=0;
    for(int i=0;i<n;i++){
        if(s!=x[i].a){
            flag=1;
        }
    }
    if(flag==0){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        s+=x[i].a;
    }
    int sum=0;
    int j=n-1;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[j]){
            sum+=x[i].id;
        }
        j--;
    }
    cout<<sum;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
