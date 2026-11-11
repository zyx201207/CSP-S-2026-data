#include<iostream>
using namespace std;
struct letters{
    int num;
    char letter;
};
letters let[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>let[i].num>>let[i].letter;
    }
    int l=0;
    int r=n-1;
    int great;
    unsigned long long ans=0;
    while(l<r){
        if(let[l].num<let[r].num){
                great=r;
            if(let[l].letter==let[r].letter){
                let[r].num-=let[l].num;
                l++;
            }
            else{
                ans+=let[l].num;
                let[r].num-=let[l].num;
                l++;
            }
        }
        else{
            great=l;
            if(let[l].letter==let[r].letter){
                let[l].num-=let[r].num;
                r--;
            }
            else{
                ans+=let[r].num;
                let[l].num-=let[r].num;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
