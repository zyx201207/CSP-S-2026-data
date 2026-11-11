#include<bits/stdc++.h>
using namespace std;
struct e{
    long long a;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    e n[200005];
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>n[i].a>>n[i].c;
    }
    int i=0,j=m-1;
    long long sum=0;
    while(i<j){
        int minn=min(n[i].a,n[j].a);
        if(n[i].c!=n[j].c){
            sum+=minn;
            if(n[i].a>n[j].a){
                n[i].a-=minn;
                j--;
            }else if(n[i].a<n[j].a){
                n[j].a-=minn;
                i++;
            }else{
                i++,j--;
            }
        }else{
            if(n[i].a>n[j].a){
                n[i].a-=minn;
                j--;
            }else if(n[i].a<n[j].a){
                n[j].a-=minn;
                i++;
            }else{
                i++,j--;
            }

        }
    }
    cout<<sum;
}
