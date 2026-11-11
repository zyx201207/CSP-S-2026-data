#include<bits/stdc++.h>
#define L long long
using namespace std;
struct str{
    L a;
    char c;
};
int main(){
    int n;
    vector<str> uncmp;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int l=0;
    for(int i=1;i<=n;i++){
        L a;char c;
        cin>>a>>c;
        l+=a;
        uncmp.push_back(str{a=a,c=c});
    }
    L ans=0;
    while(uncmp.size()>1){
        if(uncmp[0].c!=uncmp[uncmp.size()-1].c){
            if(uncmp[0].a>uncmp[uncmp.size()-1].a){
                ans+=uncmp[uncmp.size()-1].a;
                uncmp[0].a-=uncmp[uncmp.size()-1].a;
                uncmp.erase(uncmp.begin()+uncmp.size()-1);
            }
            else if(uncmp[0].a<uncmp[uncmp.size()-1].a){
                ans+=uncmp[0].a;
                uncmp[uncmp.size()-1].a-=uncmp[0].a;
                uncmp.erase(uncmp.begin());
            }
            else{
                ans+=uncmp[0].a;
                uncmp.erase(uncmp.begin()+uncmp.size()-1);
                uncmp.erase(uncmp.begin());
            }
        }
        else{
                if(uncmp[0].a>uncmp[uncmp.size()-1].a){
                    uncmp[0].a-=uncmp[uncmp.size()-1].a;
                    uncmp.erase(uncmp.begin()+uncmp.size()-1);
                }
                else if(uncmp[0].a<uncmp[uncmp.size()-1].a){
                    uncmp[uncmp.size()-1].a-=uncmp[0].a;
                    uncmp.erase(uncmp.begin());
                }
                else{
                    uncmp.erase(uncmp.begin()+uncmp.size()-1);
                    uncmp.erase(uncmp.begin());
                }
        }
    }
    cout<<ans;
    return 0;
}
