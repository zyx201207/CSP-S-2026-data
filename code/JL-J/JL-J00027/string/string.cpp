#include<iostream>
using namespace std;

typedef long long ll;

int parts;
ll arr[200000+125];
char ch[200000+125];
ll chg=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>parts;
    for(int i=0;i<parts;i++){
        cin>>arr[i]>>ch[i];
    }
    int l=0,r=parts-1;
    while(l<r){
        if(arr[l]>arr[r]){
            ll delta=arr[r];
            arr[l]-=arr[r];
            if(ch[l]!=ch[r]){
                chg+=delta;
            }
            r--;
        }
        else if(arr[l]<arr[r]){
            ll delta=arr[l];
            arr[r]-=arr[l];
            if(ch[l]!=ch[r]){
                chg+=delta;
            }
            l++;
        }
        else{
            if(ch[l]!=ch[r]){
                chg+=arr[l];
            }
            l++,r--;
        }
    }
    cout<<chg;
}
