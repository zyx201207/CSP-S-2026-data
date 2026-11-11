#include<bits/stdc++.h>
using namespace std;
int main(){
    std::cin.tie(0);
    std::cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>ma(n,vector<int>(31,0));
    vector<int> a1(n);

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        a1[i]=a;
        int j=0;
        while(a>0){
            int cur=a%2;
            ma[i][j]=cur;
            a/=2;
            j++;
        }
    }

    vector<int> ch(n,1);
    for(int i=31;i>=0;i--){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(!ch[j]) continue;
            if(ma[j][i]) cnt++;
        }
        if(cnt>=m){
            for(int j=0;j<n;j++){
                if(!ch[j]) continue;
                if(!ma[j][i]) ch[j]=0;
            }
        }
    }

    long long ret=(1<<31)-1;
    for(int i=0;i<n;i++){
        //cout<<ret<<" "<<a1[i]<<" "<<ch[i]<<endl;
        if(ch[i]) ret=ret&a1[i];
    }

    cout<<ret<<endl;
    return 0;
}
