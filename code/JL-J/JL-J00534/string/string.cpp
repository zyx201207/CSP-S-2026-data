#include <bits/stdc++.h>
using namespace std;
long long n,ans,x,y;
int a[250000];
char b[250000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int k=1;k<=n;k++){
        cin>>a[k]>>b[k];
    }
    int i=1,j=n;
    x+=a[i];
    y+=a[j];
    while(i<j){
        if(b[i]==b[j]){
            if(x==y){
                i++;
                j--;
                x=a[i];
                y=a[j];
            }
            else if(x>y){
                x-=y;
                j--;
                y=a[j];
            }
            else{
                y-=x;
                i++;
                x=a[i];
            }
            continue;
        }
        if(x==y){
            ans+=x;
            i++;
            j--;
            x=a[i];
            y=a[j];
        }
        else if(x>y){
             ans+=y;
             x-=y;
             j--;
             y=a[j];
        }
        else{
            ans+=x;
            y-=x;
            i++;
            x=a[i];
        }
    }
    cout<<ans;
    return 0;
}
