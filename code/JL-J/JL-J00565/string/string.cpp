#include<bits/stdc++.h>
using namespace std;
int n,a[200005],k=0;
char c[200005];
char s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            k++;
            s[k]=c[i];
        }
    }
    int w=k;int q=0,i=0;
    if(k%2==0){
        while(w-q==1){
            w--;
            q++;
            if(s[w]!=s[q]){
                i=1;
                break;
            }
        }
    }
    else{
        while(w==q){
            w--;
            q++;
            if(s[w]!=s[q]){
                i=1;
                break;
            }
        }
    }
    int kk=0;
    if(i==0){
        cout<<0;
        return 0;
    }
    return 0;
}
