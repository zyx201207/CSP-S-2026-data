#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long a,b,d;
    vector<long long> c;
    cin>>a>>b;
    for(long long i=0;i<a;i++){
        cin>>d;
        c.push_back(d);
    }
    long long ans[310000]={0};
    for(long long i=0;i<a;i++){
        vector<long long> n;
        n.push_back(c[i]);
        for(long long j=i+1;j<a;j++){
            n.push_back(c[j]);
            long long k=0;
            long long ss = n.size();
            for(k;k<ss-1;k++){
                if(n[k]==c[j]){
                    break;
                }
            }
            for(long long l=k+1;l<ss;l++){
                n.pop_back();
            }
        }
        for(long long j=0;j<n.size();j++){
            ans[n[j]]++;
        }
    }
    for(int i=1;i<=b;i++){
        cout<<ans[i];
        if(i!=b){
            cout<<" ";
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
