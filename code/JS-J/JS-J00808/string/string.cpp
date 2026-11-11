#include<bits/stdc++.h>
using namespace std;
struct node{
    long long n;
    char letter;
};
vector<node> V(1e6+10);
int siz=0;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        char le;
        cin>>t>>le;
        if(i==1){
            V[siz].n=t;
            V[siz++].letter=le;
            continue;
        }
        if(V[siz-1].letter==le){
            //cout<<'G'<<endl;
            V[siz-1].n+=t;
        }
        else{
            V[siz].n=t;
            V[siz++].letter=le;
        }
    }
    if(siz==1){
        cout<<0;
        return 0;
    }
    long long left=0,right=siz-1;
    long long ans=0;
    while(left<right){
        long long need_num=V[left].n;
        char need_letter=V[left].letter;
        while(need_num>0){
            if(left==right){
                cout<<ans;
                return 0;
            }
            if(V[right].letter==need_letter){
                if(V[right].n>=need_num){
                    V[right].n-=need_num;
                    need_num=0;
                    if(V[right].n==0){
                        right--;
                    }
                }
                else{
                    need_num-=V[right].n;
                    V[right].n=0;
                    right--;
                }
            }
            if(V[right].letter!=need_letter){
                //cout<<left<<' '<<right<<endl;
                if(V[right].n>=need_num){
                    ans+=need_num;
                    V[right].n-=need_num;
                    need_num=0;
                    if(V[right].n==0){
                        right--;
                    }
                }
                else{
                    ans+=V[right].n;
                    need_num-=V[right].n;
                    V[right].n=0;
                    right--;
                }
            }
        }
        left++;
    }
    cout<<ans;
    return 0;
}
