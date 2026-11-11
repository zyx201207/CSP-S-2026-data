#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a;
long long sum=0;
char c;
string s="";
string shui="";

int main(){
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    //cout<<"okk \n";


    for(int i=0;i<n;i++){
        cin>>a>>c;
        sum=sum+a;
        //cout<<sum<<"ok \n";
        while(a--)s=s+c;

    }
    //cout<<"ok";
    //cout<<sum;

    int k=sum/2;
    for(int i=k-1;i>=0;i--){
        shui=shui+s[i];
    }
    //cout<<shui<<"\n"<<s<<'\n';
    //cout<<shui.size()<<"\n"<<s.size()<<'\n';
    int ans=0;
    for(int i=k+1;i<sum;i++){
        //cout<<shui[i-k-1]<<" "<<s[i]<<"\n";
        if(shui[i-k-1]!=s[i]){
            ans++;
        }
    }
    cout<<ans;



    return 0;
}
