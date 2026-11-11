#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e5+5;
const long long A=1e6;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int k=1;k<=n;k++){
        cin>>a[k]>>c[k];
    }
    char str[A];
    int q=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            str[q]=c[i];
            q++;
        }
    }
    int lens=0;
    for(int i=1;i<=n;i++){
        lens+=a[i];
    }
    int d=0;
    if(lens%2!=0){
        int target=(lens+1)/2;
        int l=target-1;
        int r=target+1;
        while(r<=lens){
            if(str[l]!=str[r]){
                d++;
            }
            l--;
            r++;
        }
    }
    else if(lens%2==0){
        int left[A/2];
        int right[A/2];
        int l=1;
        int r=lens/2+1;
        for(int i=1;i<=n/2;i++){
            if(str[l]!=str[r]) d++;
            l++;
            r++;
        }
    }
    cout<<d;
    return 0;
}
